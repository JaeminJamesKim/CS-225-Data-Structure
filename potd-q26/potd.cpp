// Your code here
#include "potd.h"
#include <iostream>
#include <string>

std::string getFortune(const std::string &s){
    int sum = 0;
    int length = s.length();
    std::string fortune[7]= {"You will suffer from CS 225",
    "Wade will haunt you semester long",
    "You will feel so small against other CS majors",
    "God help me plz",
    "You will get at least a B. PLEASEKLJAL:FKJ",
  "more fortunes",
"and more"};

    for (int i = 0; i < length; i++) {
        sum += (int)s[i] * (length+i);
    }

return fortune[sum % 8];
}
