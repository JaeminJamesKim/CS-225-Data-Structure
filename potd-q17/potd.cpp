#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {
  // your code here!
  // Node * foo = new Node;
  // foo->next_= *head;
  // head=&foo;
  //
  // while(foo!=NULL){
  //   if(foo->data_ < insert->data_){
  //     foo->next_=insert;
  //   }
  //   else if(foo->data_ ==insert->data_){
  //     foo->next_=insert;
  //   }
  // }

  Node * foo = *head;
  if(foo == NULL){
    *head=insert;
    insert->next_ = NULL;
    return;
  }

  else if(foo->data_ >= insert->data_){
    *head=insert;
    insert->next_ = foo;
    foo=insert;
  }
  else{
    Node * prev = *head;
    foo = foo->next_;
    while(foo!=NULL){
      if(foo->data_ >= insert->data_){
            insert->next_ = foo;
            prev->next_=insert;
            return;
          }
          foo=foo->next_;
          prev=prev->next_;
    }
    prev->next_=insert;
    insert->next_=NULL;
  }
}
