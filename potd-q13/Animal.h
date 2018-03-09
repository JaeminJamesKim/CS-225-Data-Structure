// Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
private:
  std::string type_;

protected:
  std::string food_;

public:
  std::string getType();
  std::string getFood();
  void setType(std::string s1);
  void setFood(std::string s2);
  virtual std::string print();

  Animal();
  Animal(std::string a1, std::string a2);
};


#endif
