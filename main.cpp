
#include "server.h"
#define SERVER_PORT 1234
#define QUEUE_SIZE 5
#define FILE_NAME "data"

int main(int argc, char* argv[])
{
//    LinkedList * list = new LinkedList();
//    Node* tmp = list->push_back(10, "aaa");
//    Node* tmp1 = list->push_back(20, "bbb");
//    Node* tmp2 = list->push_back(30, "ccc");
//    list->remove(tmp1);
    Cache* cache = new Cache(3);
    cache->put("aaaaaa",1);
    cache->put("bbbbbb",2);
    cache->put("cccccc",3);
    cache->get(1);
    cache->get(10);
    cache->put("dddddd",4);
    cache->put("eeeeee",5);

//    Node* index = list->get_first();
//    cout << index->get_data();
//    cout << index->get_next()->get_data();
//    Server* server = new Server(100, 1234);
//    server->run();
    return(0);
}