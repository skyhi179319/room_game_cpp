#include <iostream>
class scoring {
public:
    int remaining_health;
    bool has_gun;
    std::string mode;
    // importing the sys class from main.cpp
    sys s;
    scoring(int rh,bool hg,std::string m) {
        remaining_health = rh;
        has_gun = hg;
        mode = m;
    }
    int remainingHealth(){
        return this->remaining_health;
    }
    int hasGun(){
        if(this->has_gun == true){
            return 100;
        } else{
            return 0;
        }
    }
    int modeScore(){
        if(this->mode == "easy"){
            return 25;
        } else if(this->mode == "hard"){
            return 50;
        }
    }
    int returnTotal(){
        int pre1 = s.math.add(this->remainingHealth(), this->hasGun());
        int math = s.math.multiply(s.math.add(pre1,modeScore()),10);
        return math;
    }
};