#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"
#include <iostream>
#include <string>

class Derived : public Base{
  public:
  std::string foo();
  virtual std::string bar();
  virtual ~Derived();
};



#endif
