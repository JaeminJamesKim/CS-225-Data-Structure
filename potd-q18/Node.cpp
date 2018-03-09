#include "Node.h"
#include <iostream>
#include <string>


using namespace std;

void sortList(Node **head) {
  // your code here!

  Node *foo = *head;
  Node *after = foo->next_;
  if(foo == NULL){
    *head=insert;
    insert->next_ = NULL;
    return;
  }

  else{
  while(foo!=NULL){
    if(foo->data_ >((after)->data_)){
      after->next_= foo;
      after = after->next_;
      foo = after;

    }
      foo=foo->next_;

  }
}

}


Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
