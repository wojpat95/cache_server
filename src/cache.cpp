#include "cache.h"

using namespace std;

Cache::Cache(int size) {
    this->size = size;
}


Cache::~Cache() {

}

string Cache::get(int lineNumber) {
    // iterator with lineNumber as a key
    auto got = hashIndex.find(lineNumber);
    if (got == hashIndex.end()){
        return "";
    }
    // mapped pointer to element in list
    Node* val_pointer = got->second;
    string result = val_pointer->get_data();

    // move node to the end of list (LRU)
    data.remove(val_pointer);
    Node* index = data.push_back(lineNumber, result);
    hashIndex[lineNumber] = index;
    return result;
}

void Cache::put(string line, int lineNumber) {
    //if not full add line to the end and pointer insert to hashtable
    if(data.size() < size){
        Node* index = data.push_back(lineNumber, line);
        hashIndex[lineNumber] = index;
    }
    // remove the oldest line from data and index from hashtable then add new line to the end, pointer insert to hashtable
    else{
        int number = data.get_first()->get_number();
        Node* val_pointer = hashIndex[number];
        data.remove(val_pointer);
        hashIndex.erase(number);
        Node* index = data.push_back(lineNumber, line);
        hashIndex[lineNumber] = index;
    }
}