#include <iostream>
#include <string>
#include "Food.h"
#include "q5.h"

int main(){
  Food f;
  f.set_quantity(5);
  Food *ptr=&f;
  std::cout << "You have " << ptr->get_quantity()<< " apples."<< '\n';

  increase_quantity(ptr);
  std::cout << "You have " << ptr->get_quantity()<< " apples."<< '\n';

  return 0;
}
