#include <iostream>
// boss for tunnel level
class boss {
public:
    int health;
    int last_damage;
    boss() {
        health = 100;
        last_damage = 0;
    }
    void minusHealth(int h){
        int predicted_health = health - h;
        if(predicted_health < 0){
            health = 0;
        } else{
            health = health - h;
            this->set_lastDamage(h);
        }
    }
    int getHealth(){
        return health;
    }
    void set_lastDamage(int i){
        last_damage = i;
    }
    int returnLastDamage(){
        return last_damage;
    }
};
