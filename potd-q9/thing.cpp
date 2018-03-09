#include "thing.h"// Your code here!
#include <iostream>
#include <string>

using namespace potd;

Thing::Thing(int size)
{
  props_ct_=-1;
  props_max_=size;
  properties_ = new std::string[props_max_];
  values_ = new std::string[props_max_];

  }

Thing::Thing(const Thing & other){
_copy(other);
}

Thing & Thing::operator=(const Thing & other){
if(this != &other){
  _destroy();
  _copy(other);
}
return *this;

}

Thing::~Thing(){
_destroy();
}

int Thing::set_property(std::string s1,std::string s2){
props_ct_++;
if(props_ct_>props_max_){
    return -1;
}
else if(properties_[props_ct_]==s1){
values_[props_ct_]=s2;
  return props_ct_;
}
else{
  properties_[props_ct_]=s1;
  values_[props_ct_]=s2;
}
return props_ct_;
}

std::string Thing::get_property(std::string s3){
std::string val = "";
for(int i =0; i<props_max_; i++){
  if(properties_[i]==s3)
  val=values_[i];
}
return val;
}

void Thing::_copy(const Thing & other){
  props_ct_=other.props_ct_;
  props_max_=other.props_max_;

  properties_ = new std::string[props_max_];
  values_=new std::string[props_max_];
  for(int i = 0; i<props_max_; i++){
    properties_[i]=other.properties_[i];
    values_[i]=other.values_[i];
  }
}

void Thing::_destroy(){
  if(properties_ !=NULL){
    delete[] properties_;
    properties_=NULL;
  }
  if(values_ !=NULL){
    delete[] values_;
    values_=NULL;
  }

}
