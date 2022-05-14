#include <iostream>
// boss for tunnel level
class boss {
public:
    int health;
    boss() {
        health = 100;
    }
    void minusHealth(int h){
        health = health - h;
    }
    int getHealth(){
        return health;
    }
};
