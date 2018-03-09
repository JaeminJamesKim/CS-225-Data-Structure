#include "hello.h"
#include <iostream>
#include <string>

using namespace std;

string hello(){
    string your_age = "24";
    string your_name = "Jaemin";
    string result = "Hello world! My name is " +  your_name + " and I am " + your_age + " years old.";
    return result;
}
