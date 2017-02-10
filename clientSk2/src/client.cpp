#include "client.h"

Client::Client(char* server, short port) {
    serverAddress_ = server;
    serverPort_ = port;
}

Client::~Client() {
}

void Client::run() {
    while(1){
        getRequest();
        create();
        requestHandler(request_);
        responseHandler();
        close(server_);
    }

}
void Client::create() {
    struct sockaddr_in sck_addr;

    printf ("Usługa %d z serwera %s :\n", serverPort_, serverAddress_);

    memset (&sck_addr, 0, sizeof sck_addr);
    sck_addr.sin_family = AF_INET;
    inet_aton (serverAddress_, &sck_addr.sin_addr);
    sck_addr.sin_port = htons (serverPort_);

    if ((server_ = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror ("Nie można utworzyć gniazdka");
        exit (EXIT_FAILURE);
    }

    if (connect (server_, (struct sockaddr*) &sck_addr, sizeof sck_addr) < 0) {
        perror ("Brak połączenia");
        exit (EXIT_FAILURE);
    }

}

bool Client::requestHandler(char* request) {
    write(server_,request,sizeof(request));
    return true;
}

bool Client::responseHandler() {
    char response[1024];
    for (int i=0; i<1024; i++)
        response[i] = 0;
    read(server_,response,sizeof(response));
    write(1, response, sizeof(response));
    return true;
}

void Client::getRequest() {
    char request[50];
    for(int i = 0; i < 50; i++)
        request[i] = 0;
    read(1,request,sizeof(request));
    strcpy(request_, request);
}