#include <iostream>
#include <string>
using namespace std;

#include "square.h"

Square::Square() {
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName) {
  name = newName;
}

void Square::setLength(double newVal) {
  *lengthptr = newVal;
}

string Square::getName() const {
  return name;
}

double Square::getLength() const {
  return *lengthptr;
}

Square::Square(const Square & other) {
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square() {
    delete lengthptr;
}

Square Square::operator+(const Square & other) {
  Square s;
  s.setName((*this).getName()+other.getName());
  s.setLength((*this).getLength() + other.getLength());
  return s;
}

Square & Square::operator=(const Square & other){
  if(this==&other){
    return (*this);
  }
  (*this).setName(other.getName());
  (*this).setLength(other.getLength());
  return (*this);

}
