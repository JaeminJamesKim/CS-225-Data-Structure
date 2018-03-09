#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

class Stack {
// int top;
//
// public:
//   int size() const;
//   bool isEmpty() const;
//   void push(int value);
//   int pop();
//   int a[max];

private:
       struct node{
           int val;
           node * next;
           node() {val = 0; next = NULL;}
           node(int newVal) {val = newVal; next = NULL;}
       };
       node * head;
       int count;
   public:
       Stack();
       ~Stack();
       int size() const;
       bool isEmpty() const;
       void push(int value);
       int pop();
void print();
};

#endif
