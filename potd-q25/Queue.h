#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>

class Queue {
private:
  struct node{
      int val;
      node * next;
      node() {val = 0; next = NULL;}
      node(int newVal) {val = newVal; next = NULL;}
  };
  node * front; // front
  node * rear; // tail
  int count;

public:
    Queue();
    ~Queue();
    int size() const;
    bool isEmpty() const;
    void enqueue(int value);
    int dequeue();
};

#endif
