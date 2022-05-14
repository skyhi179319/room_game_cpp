#include <iostream>
#include <time.h>
#include <stdlib.h>
class math {       
  public:            
    void add(int x, int y) {
      std::cout << x + y;
    }
    void multiply(int x, int y){
      std::cout << x * y;
    }
    void subtract(int x,int y){
      std::cout << x - y;
    }
    void divide(int x,int y){
      std::cout << x / y;
    }
    int random(int high,int low){
        srand(time(0));
        return rand() % high + low;
    }
};