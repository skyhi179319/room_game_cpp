// testing purposes
//#include "../headers//sys.h"
class weapons{
public:
    int knife = 10;
    int gun = 20;
};
class damage {
public:
    sys m;
    int do_damage(int damage, int critical){
        int damage_n = m.math.add(damage,critical);
        return damage_n;
    }
};