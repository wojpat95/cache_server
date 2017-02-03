#include "linkedList.h"


Node::Node(int number, string data, Node * prev, Node * next) {
    this->number = number;
    this->data = data;
    this->prev = prev;
    this->next = next;
}
Node::~Node() {

}
Node* Node::get_next() {
    return next;
}
Node* Node::get_prev() {
    return prev;
}
string Node::get_data() {
    return data;
}
int Node::get_number() {
    return number;
}
void Node::set_next(Node * next) {
    this->next = next;
}

void Node::set_prev(Node * prev) {
    this->prev = prev;
}



LinkedList::LinkedList() {
    first = NULL;
    last = NULL;
    list_size = 0;
}

LinkedList::~LinkedList() {

}

Node* LinkedList::push_back(int number, string data) {
    Node * node = new Node(number,data,NULL,NULL);
    if (first == NULL){
        first = node;
        last = node;
    } else{
        node->set_prev(last);
        last->set_next(node);
        last = node;
    }
    list_size++;
    return node;
}

int LinkedList::size() {
    return list_size;
}

bool LinkedList::remove(Node * node) {
    if (node->get_prev() && node->get_next()){
        node->get_prev()->set_next(node->get_next());
        node->get_next()->set_prev(node->get_prev());
        delete node;
        list_size--;
        return true;
    }
    if (node->get_prev() == NULL && node->get_next() == NULL){
        first = NULL;
        last = NULL;
        list_size--;
        delete node;
    }
    if (node->get_prev() == NULL){
        first = node->get_next();
        first->set_prev(NULL);
        delete node;
        list_size--;
        return true;
    }
    if (node->get_next() == NULL){
        last = node->get_prev();
        last->set_next(NULL);
        delete node;
        list_size--;
        return true;
    }
    return false;

}

Node* LinkedList::get_first() {
    return first;
}

Node* LinkedList::get_last() {
    return last;
}