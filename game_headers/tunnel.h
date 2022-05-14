#include "boss.h"
class tunnel {
public:
    int health;
    boss b;
    void simulate_boss(int minus_health){
        b.minusHealth(minus_health);
    }
};
