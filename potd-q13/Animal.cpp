// Animal.cpp
#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal(){
  type_="cat";
  food_="fish";
}

Animal::Animal(std::string a1, std::string a2){
  type_=a1;
  food_=a2;
}

std::string Animal::getType(){
  return type_;
}

std::string Animal::getFood(){
  return food_;
}
void Animal::setType(std::string s1){
  type_=s1;
}

void Animal::setFood(std::string s2){
  food_=s2;
}
std::string Animal::print(){
  std::string what = "";
  what = "I am a "+this->getType()+".";
  return what;
}
