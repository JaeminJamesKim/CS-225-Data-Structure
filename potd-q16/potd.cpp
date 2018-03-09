#include "potd.h"
#include <iostream>
#include <string>

using namespace std;

string stringList(Node *head) {
    // your code here!
    Node *foo = new Node;
    foo=head;
    std::string output="";
    std::string arrow="->";
    int count = 0;
    if(foo==NULL){
      return "Empty list";
    }
    else if(foo->next_==NULL){
      output+="Node " + std::to_string(count)+": "+std::to_string(foo->data_);
      foo=foo->next_;
      return output;
    }

    else{
      output+="Node " + std::to_string(count)+": "+std::to_string(foo->data_);
      foo=foo->next_;
      count++;
      while (foo!=NULL){
          output+= " "+arrow+" " + "Node "+ std::to_string(count) + ": " + std::to_string(foo->data_);
          count++;
          foo=foo->next_;

      }
      return output;
    }

  }
