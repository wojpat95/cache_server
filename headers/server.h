#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "linkedList.h"
#include "cache.h"
#include <unistd.h>

#ifndef MEMCASHEDSERVER_SERVER_H
#define MEMCASHEDSERVER_SERVER_H

class Server{
public:
    Server(int, int);
    ~Server();
    void run();
protected:
    void create(struct sockaddr_in&);
    void serve();
    string requestHandler(int);
    void responseHandler(int, string);
    string cacheHandler(string);
    int server_;
    int serverPort_;
    int queueSize_;
    Cache* cache_;
    string file_;
};


#endif //MEMCASHEDSERVER_SERVER_H
