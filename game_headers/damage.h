// testing purposes
//#include "../headers//sys.h"
#include <iostream>
class weapons{
public:
    int knife;
    int gun;
    int spear;
    weapons(std::string mode){
        if(mode == "easy"){
            knife = 10;
            gun = 20;
            spear = 10;
        } else if(mode == "hard"){
            knife = 10;
            gun = 20;
            spear = 20;
        }
    }

};
class damage {
public:
    sys m;
    int do_damage(int damage, int critical){
        int damage_n = m.math.add(damage,critical);
        return damage_n;
    }
};