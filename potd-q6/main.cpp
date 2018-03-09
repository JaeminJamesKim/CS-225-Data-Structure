#include <iostream>
#include <string>
#include "q6.h"
#include "student.h"

int main(){
  potd::Student sally;
  sally.set_name("sally");
  sally.set_grade(5);

  potd::Student s = sally;

  std::cout<< sally.get_name() << " is in grade "<<sally.get_grade()<<std::endl;
  graduate(sally);
  std::cout<< sally.get_name() << " is in grade "<<sally.get_grade()<<std::endl;





  return 0;
}
