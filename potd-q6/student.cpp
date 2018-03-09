#include "student.h"
#include <iostream>
#include <string>

namespace potd{
std::string Student::get_name(){
  return name_;
}

int Student::get_grade(){
  return grade_;
}

void Student::set_name(std::string n){
  name_=n;
}

void Student::set_grade(int g){
  grade_=g;
}

Student::Student(){

}
}
