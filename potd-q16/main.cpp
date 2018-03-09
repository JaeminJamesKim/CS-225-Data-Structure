#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node

  Node* n = new Node;
  n->data_=1;
  n->next_=NULL;
  cout<<stringList(n) <<endl;


  // Test 3: A list with more than one node
  for(int i = 5; i > 0; i--){
          Node * newNode = new Node;
          newNode->data_ = i;
          if(head == NULL){
              head = newNode;
              newNode->next_ = NULL;
          }
          else{
              newNode->next_ = head;
              head = newNode;
          }
          cout<<stringList(newNode) <<endl;
      }



  return 0;
}
