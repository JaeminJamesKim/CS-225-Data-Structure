#include <iostream>
#include <string>
#include "Bar.h"
#include "Foo.h"

using namespace potd;

Bar::Bar(std::string nname){
    f_ = new Foo(nname);
}

Bar::Bar(const Bar & tthat) {
    f_= new Foo(tthat.f_->name_);
}


Bar::~Bar(){
  Foo::count_--;
}


Bar & Bar::operator = (const Bar & other){
    f_->name_ = other.name_;
    Foo::count_++;
    return *this;
}


std::string Bar::get_name(){
  return f_->get_name();
}
