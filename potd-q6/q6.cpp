#include "q6.h"
#include "student.h"
#include <iostream>
#include <string>

void graduate(potd::Student & s){
  s.set_grade(s.get_grade()+1);
}
