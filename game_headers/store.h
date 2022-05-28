// testing purposes
/*
 * #include "../headers//sys.h"
*/

#include "config.h"
#include <iostream>
class coins{
public:
    int amount;
    coins(){
        sys s;
        if(s.file.exist(coins_file)){
            int coins_have = s.convert.convertFromString(s.file.readFile(coins_file));
            if(MAX_COINS < coins_have){
                amount = coins_have;
            } else{
                amount = 30;
            }
        } else{
            amount = 30;
        }
    }
    bool buy(int i){
        if(i > amount){
            return  false;
        } else{
            amount = amount - i;
            return true;
        }
    }
    void add(int i){
        amount = amount + i;
    }

};
class store {
public:
    sys m;
    struct{
        int twoTimesMultiplier;
        int tenHealth;
        int gun_damage_cost;
    }prices;
    void setPrices(){
        prices.twoTimesMultiplier = 50;
        prices.tenHealth = 15;
        prices.gun_damage_cost = 100;
    }
};