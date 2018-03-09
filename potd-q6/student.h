#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

namespace potd{
class Student{
private:
  std::string name_;
  int grade_;

public:
  std::string get_name();
  void set_name(std::string n);
  int get_grade();
  void set_grade(int g);
  Student();

};
}


#endif
