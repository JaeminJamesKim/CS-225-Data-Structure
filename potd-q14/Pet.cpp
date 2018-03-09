// Pet.cpp
#include <iostream>
#include <string>
#include "Pet.h"
#include "Animal.h"

Pet::Pet():Animal(){
  name_= "Fluffy";
  owner_name_="Cinda";
}

//Hmmmm
Pet::Pet(std::string p1, std::string p2, std::string p3, std::string p4)
:Animal(p1,p2){
name_=p3;
owner_name_=p4;
}

void Pet::setFoodName(std::string s1){
  food_=s1;
}

std::string Pet::getFoodName(){
  return food_;
}
void Pet::setName(std::string s2){
  name_=s2;
}
std::string Pet::getName(){
  return name_;
}
void Pet::setOwnerName(std::string s3){
  owner_name_=s3;
}
std::string Pet::getOwnerName(){
  return owner_name_;
}
std::string Pet::print(){
  return "My name is "+ name_;
}
