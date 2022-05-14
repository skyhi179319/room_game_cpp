#include <iostream>
#include "math.h"
#include "input.h"
#include "convert.h"
class sys {       
  public:     
    // imports all header class
    math math;
    input input;
    convert convert;
    // console methods
    void log(std::string x){
      std::cout << x + "\n";
    }
    void log(int x){
      std::cout << x;
      std::cout << "\n";
    }
};