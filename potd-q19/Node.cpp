#include "Node.h"

using namespace std;

void mergeList(Node *first, Node *second) {
  // your code here!
  Node *p_curr = first, *q_curr = second;
  Node *p_next, *q_next;

      while (p_curr != NULL && q_curr != NULL)
      {
          p_next = p_curr->next_;
          q_next = q_curr->next_;

          q_curr->next_ = p_next;
          p_curr->next_ = q_curr;

          p_curr = p_next;
          q_curr = q_next;
     }
     while(q_curr != NULL && p_curr ==NULL){
       q_next=q_curr->next_;
       q_curr->next_=q_next;
       q_curr=q_next;
     }
     while(p_curr != NULL && q_curr == NULL){
       p_next=p_curr->next_;
       p_curr->next_=p_next;
       p_curr=p_next;
     }
     first = p_curr;
     second = q_curr;
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
