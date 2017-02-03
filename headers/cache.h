#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "linkedList.h"

using namespace std;

#ifndef MEMCASHEDSERVER_CACHE_H
#define MEMCASHEDSERVER_CACHE_H

class Cache{
public:
    Cache(int);
    ~Cache();
    void put(string, int);
    string get(int);

private:
    unordered_map<int,Node*> hashIndex;
    LinkedList data;
    int fileSize;
    int size;
};
#endif //MEMCASHEDSERVER_CACHE_H
