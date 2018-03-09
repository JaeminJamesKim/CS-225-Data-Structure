#include "Node.h"

using namespace std;

Node *listUnion(Node *first, Node *second) {
  // your code here
  Node *ufront, *urear;
  Node *utemp=NULL;

int flag = 0;
while (first != NULL)
{
  ufront=NULL;
    while (ufront != NULL)
    {
        if (ufront->data_ == first->data_)
        {
            flag = 1;
        }
        ufront = ufront->next_;
    }
    if (flag)
    {
        flag = 0;
    }
    else
    {
        utemp->data_ = first->data_;
        utemp->next_ = NULL;
        if (ufront == NULL)
        {
            ufront = utemp;
        }
        else
        {
            urear->next_ = utemp;
        }
        urear = utemp;
    }
    first = first->next_;
}
while (second != NULL)
{
    ufront = NULL;
    while (ufront != NULL)
    {
        if (ufront->data_ == second->data_)
        {
            flag = 1;
        }
        ufront = ufront->next_;
    }
    if (flag)
    {
        flag = 0;
    }
    else
    {
        utemp->data_ = second->data_;
        utemp->next_ = NULL;
        if (ufront == NULL)
        {
            ufront = utemp;
        }
        else
        {
            urear->next_ = utemp;
        }
        urear = utemp;
    }
    second = second->next_;
}
  // Node *result = NULL;
  // Node *t1 = first, *t2 = second;
  //
  //   while (t1 != NULL)
  //   {
  //     if(result==NULL){
  //       result = t1;
  //     }
  //     else{
  //       t1->next_= result;
  //       result = t1;
  //     }
  //     t1 = t1->next_;
  //   }
  //
  //   // Insert those elements of list2 which are not
  //   // present in result list
  //   while (t2 != NULL)
  //   {
  //     // if (!isPresent(result, t2->data_))
  //       if(result==NULL){
  //         result = t2;
  //       }
  //       else{
  //         t2->next_= result;
  //         result = t2;
  //       }
  //       t2 = t2->next_;;
  //   }
  //
  //   return result;
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
