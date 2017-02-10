#include <iostream>
#include "client.h"
using namespace std;

#define SERVER_ADDRESS "127.0.0.1"
#define PORT_SERVER 1234
int main() {
    Client* client = new Client(SERVER_ADDRESS, PORT_SERVER);
    client->run();
    return 0;
}