#include "Queue.h"

#include<string>
#include<iostream>

Queue::Queue() {
  rear = NULL;
  front = NULL;
  count = 0;
}

Queue::~Queue(){
  node * current = rear;
    if (rear) {
        node * currentNext = current -> next;
        while (currentNext) {
            delete current;
            current = currentNext;
            currentNext = current -> next;
        }
        delete current;
}
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return count;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  return count==0;
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
  node * newNode = new node(value);
  std::cout<<"HMM"<<std::endl;
  if(front == NULL){              // if there is no front node
      front = newNode;
      rear=newNode;
      count=1;
    }           // make this a front node

  else{                      // else, if there is already a front node
      front->next = newNode;      // make this rear's next pointer???? why?
      front = newNode;
      count++;
    }

}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  if (!isEmpty()) {
          node * temp = rear;
          int value = rear -> val;

          rear = rear -> next;
          temp -> next = NULL;
          delete temp;
          count--;

          return value;
      }

  return -1;
}
