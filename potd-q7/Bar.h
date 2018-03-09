#ifndef BAR_H
#define BAR_H
#include <iostream>
#include <string>
#include "Foo.h"

namespace potd{
  class Bar{
    private:
      Foo * f_;

    public:
      Bar(std::string nname);
      Bar(const Bar & tthat);
      ~Bar();
      Bar & operator = (const Bar & other);
      std::string get_name();



  };


}

#endif
