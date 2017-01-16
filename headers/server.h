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
#include <time.h>

#ifndef MEMCASHEDSERVER_SERVER_H
#define MEMCASHEDSERVER_SERVER_H

class Server{
public:
    Server(int);
    ~Server();
    void run();
protected:
    void create(struct sockaddr_in&);
    void serve();

    int server_;
    int serverPort_;
    int queueSize_;
};


#endif //MEMCASHEDSERVER_SERVER_H
