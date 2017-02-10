#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

using namespace std;

#ifndef CLIENTSK2_CLIENT_H
#define CLIENTSK2_CLIENT_H

class Client{
public:
    Client(char*, short);
    ~Client();
    void run();

protected:
    void create();
    void getRequest();
    bool requestHandler(char*);
    bool responseHandler();
    int server_;
    char* serverAddress_;
    short serverPort_;
    char request_[50];

};
#endif //CLIENTSK2_CLIENT_H
