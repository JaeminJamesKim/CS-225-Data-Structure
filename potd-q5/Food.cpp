#include "Food.h"
#include <string>
#include <iostream>

std::string Food::get_name(){
  return name_;
}

void Food::set_name(std::string name1){
  name_=name1;
}

int Food::get_quantity(){
  return quantity_;
}

void Food::set_quantity(int quantity1){
  quantity_=quantity1;
}

Food::Food(){
  
}
