#include "Stack.h"


// `int size()` - returns the number of elements in the stack (0 if empty)
// int Stack::size() const {
//   int count = 0;
//   while(top!=0){
//     count++;
//     pop();
//   }
//
// }
//
// // `bool isEmpty()` - returns if the list has no elements, else false
// bool Stack::isEmpty() const {
//   return (top<0);
// }
//
// // `void push(int val)` - pushes an item to the stack in O(1) time
// void Stack::push(int value) {
// if(top>=max){
//   return;
// }
// else{
//   a[++top]=value;
// }
// }
//
// // `int pop()` - removes an item off the stack and returns the value in O(1) time
// int Stack::pop() {
//   if (top <0) {
//        return 0;
//    }
//    else{
//      int x = a[top--];
//      return x;
//    }
//
// }

Stack::Stack(){
    head = new node();
    count = 0;
}

Stack::~Stack(){
    node * current = head;
    node * currentNext = current -> next;
    while (currentNext) {
        delete current;
        current = currentNext;
        currentNext = current -> next;
    }
    delete current;
}

int Stack::size() const{
    return count;
}

bool Stack::isEmpty() const {
    return count == 0;
}

void Stack::push(int value) {
    node * newNode = new node(value);
    newNode -> next = head -> next;
    head -> next = newNode;

    count++;
}

int Stack::pop() {
    if (!isEmpty()) {
        node * temp = head -> next -> next;
        int value = head -> next -> val;

        head -> next -> next = NULL;
        delete head -> next;

        head -> next = temp;
        count--;

        return value;
    }

    return -1;
}
