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
        struct{
            bool damage;
        }gun_upgrades;
        bool twoTimesMultiplier;
    } items;
    struct {
        int wins;
        int losses;
        int ties;
    } chances;
    player(std::string firstName, std::string lastName) {
        firstname = firstName;
        lastname = lastName;
        health = 100;
        items.knife = false;
        items.flashlight = false;
        items.gun = false;
        items.twoTimesMultiplier = false;
    }
    void minusHealth(){
        health = health - 10;
    }
    void addHealth(){
        health = health + 10;
    }
    void addHealth(int i){
        health = health + i;
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
    void addGunDamage(){
        items.gun_upgrades.damage = true;
    }
    void addMultiplier(){
        items.twoTimesMultiplier = true;
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