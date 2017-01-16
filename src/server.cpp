#include "server.h"

Server::Server(int port) {
    serverPort_ = port;
    queueSize_= 100;
}

Server::~Server() {

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
        char buffer[50];
        int n;
        while ((n = read(nClientSocket, buffer, 50)) > 0){
            write(1,buffer,n);
            write(nClientSocket, buffer, n);

        }
        close(nClientSocket);
    }
}