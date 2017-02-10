#include <iostream>

using namespace std;

#ifndef MEMCASHEDSERVER_LINKEDLIST_H
#define MEMCASHEDSERVER_LINKEDLIST_H
class Node{
private:
    int number;
    string data;
    Node* next;
    Node* prev;
public:
    Node(int, string, Node*, Node*);
    ~Node();
    Node* get_next();
    Node* get_prev();
    int get_number();
    string get_data();
    void set_data(string);
    void set_next(Node*);
    void set_prev(Node*);
};

class LinkedList{
private:
    Node* first;
    Node* last;
    int list_size;
public:
    LinkedList();
    ~LinkedList();
    Node* push_back(int,string);
    bool remove(Node*);
    Node* get_first();
    Node* get_last();
    void set_first(Node*);
    void set_last(Node*);
    int size();
};
#endif //MEMCASHEDSERVER_LINKEDLIST_H
