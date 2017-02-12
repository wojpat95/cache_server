#include <algorithm>
#include <common.h>
#include "server.h"

using namespace std::chrono;

Server::Server(string file, int queueSize, int cacheSize, int port) {
    serverPort_ = port;
    this->queueSize_= queueSize;
    cache_ = new Cache(cacheSize);
    file_ = file;
}

Server::~Server() {
    close(server_);
}
void Server::run() {
    struct sockaddr_in stAddr;
    create(stAddr);
    serve();
}

void Server::create(struct sockaddr_in& stAddr) {
    int nBind, nListen;
    int nFoo = 1;

    /* address structure */
    memset(&stAddr, 0, sizeof(struct sockaddr));
    stAddr.sin_family = AF_INET;
    stAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    stAddr.sin_port = htons(serverPort_);

    /* create a socket */
    server_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_ < 0)
    {
        fprintf(stderr, "Can't create a socket.\n");
        exit(1);
    }
    setsockopt(server_, SOL_SOCKET, SO_REUSEADDR, (char*)&nFoo, sizeof(nFoo));

    /* bind a name to a socket */
    nBind = bind(server_, (struct sockaddr*)&stAddr, sizeof(struct sockaddr));
    if (nBind < 0)
    {
        fprintf(stderr, "Can't bind a name to a socket.\n");
        exit(1);
    }
    /* specify queue size */
    nListen = listen(server_, queueSize_);
    if (nListen < 0)
    {
        fprintf(stderr, "Can't set queue size.\n");
    }

}

void Server::serve() {
    string request;
    int nClientSocket;
    socklen_t nTmp;
    struct sockaddr_in stClientAddr;

    while(1)
    {
        /* block for connection request */
        nTmp = sizeof(struct sockaddr);
        nClientSocket = accept(server_, (struct sockaddr*)&stClientAddr, &nTmp);
        if (nClientSocket < 0)
        {
            fprintf(stderr, "Can't create a connection's socket.\n");
            exit(1);
        }

        printf("[connection from %s]\n", inet_ntoa((struct in_addr)stClientAddr.sin_addr));
        request = requestHandler(nClientSocket);
        responseHandler(nClientSocket, request);
        close(nClientSocket);
    }
}

string Server::requestHandler(int nClientSocket) {
    char buffer[50];
    string request = "";

    for(int i = 0; i < 50; i++)
        buffer[i] = 0;
    size_t nbytes;
    ssize_t n;
    nbytes = sizeof(buffer);
    //get request form client
    if ((n = read(nClientSocket, buffer, nbytes)) > 0) {
        request += buffer;
    }
    if(request.length() > 0){
        request.pop_back();
    }
    return request;
}

void Server::responseHandler(int nClientSocket, string request) {
    string response = "";
    size_t nbytes;
    ssize_t n;
    nbytes = sizeof(request);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    response = cacheHandler(request);
    response += "\n";
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "Time of getting the line: " << duration << " microseconds" << endl;

    char *buffer = new char[response.length() + 1];
    strcpy(buffer, response.c_str());
    // send response to client
    write(nClientSocket, buffer, response.length());
    delete [] buffer;

}

string Server::cacheHandler(string request) {
    string cachedText = "";
    int lineNumber;

    if (!Common::isNumeric(request)){
        return "ERROR: REQUEST HAS TO BE NUMERIC!\n";
    }
    if(request.length() == 0){
        return "";
    }
    lineNumber = stoi(request);
    try{
        cachedText = cache_->get(lineNumber);
    } catch(...){
            try{
                cachedText = Common::readNthLine(file_,lineNumber);
                cache_->put(cachedText,lineNumber);
            }catch(...){
                cachedText = "FILE IS SHORTER THAN " + request + " LINES";
            }
    }

    return cachedText;
}

