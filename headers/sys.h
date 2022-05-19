#include <iostream>
#include "math.h"
#include "input.h"
#include "convert.h"
#include <stdlib.h>
class sys {       
  public:     
    // imports all header class
    math math;
    input input;
    convert convert;
    // console methods
    void log(std::string x){
        std::cout << x;
        std::cout << "\n";
    }
    void log(int x){
      std::cout << x;
      std::cout << "\n";
    }
    // array
    void printArray(std::string arr[]){
        for (int i = 0; i < 4; i++) {
            std::cout << arr[i] << "\n";
        }
    }
    // create line for console
    void createLine(int x){
        std::string line;
        for (int i = 0; i < x; i++) {
            line.append("-");
        }
        std::cout << line;
        std::cout << "\n";
    }
};