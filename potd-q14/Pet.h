// Pet.h
#ifndef PET_H
#define PET_H
#include "Animal.h"
#include <iostream>
#include <string>

class Pet: public Animal{
private:
  std::string name_;
  std::string owner_name_;

public:
  Pet();
  Pet(std::string p1, std::string p2, std::string p3, std::string p4);
  void setFoodName(std::string s1);
  std::string getFoodName();
  void setName(std::string s2);
  std::string getName();
  void setOwnerName(std::string s3);
  std::string getOwnerName();
  std::string print();

};

#endif
