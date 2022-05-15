#include <iostream>
class player {
public:
    std::string firstname;
    std::string lastname;
    int health;
    struct {
        bool knife;
        bool flashlight;
        bool gun;
    } items;
    player(std::string firstName, std::string lastName) {
        firstname = firstName;
        lastname = lastName;
        health = 100;
        items.knife = false;
        items.flashlight = false;
        items.gun = false;
    }
    void minusHealth(){
        health = health - 10;
    }
    void addHealth(){
        health = health + 10;
    }
    void addKnife(){
        items.knife = true;
    }
    void addFlashlight(){
        items.flashlight = true;
    }
    void addGun(){
        items.gun = true;
    }
    int getHealth(){
        return health;
    }
    void setHealth(int h){
        health = h;
    }
    void simulate(int h){
        int predicted_health = health - h;
        if(predicted_health < 0){
            health = 0;
        } else{
            health = health - h;
        }

    }
};