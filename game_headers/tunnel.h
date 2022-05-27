#include "boss.h"
class tunnel {
public:
    boss b;
    void simulate_boss(int minus_health){
        b.minusHealth(minus_health);
    }
};