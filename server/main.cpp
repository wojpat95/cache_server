
#include "server.h"
#define FILE_PATH "../data"
#define SERVER_PORT 1234
#define QUEUE_SIZE 10
#define CACHE_SIZE 10
int main(int argc, char* argv[])
{
    Server* server = new Server(FILE_PATH, QUEUE_SIZE, CACHE_SIZE, SERVER_PORT);
    server->run();
    return(0);
}