#include <iostream>
// boss for tunnel level
class boss {
public:
    int health;
    boss() {
        health = 100;
    }
    void minusHealth(int h){
        int predicted_health = health - h;
        if(predicted_health < 0){
            health = 0;
        } else{
            health = health - h;
        }
    }
    int getHealth(){
        return health;
    }
};
