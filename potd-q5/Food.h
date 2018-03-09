#ifndef _FOOD_H
#define _FOOD_H
#include <string>
#include <iostream>

class Food{
private:
  std::string name_;
  int quantity_;

public:
  std::string get_name();
  void set_name(std::string name1);
  int get_quantity();
  void set_quantity(int quantity1);
  Food();
};

#endif
