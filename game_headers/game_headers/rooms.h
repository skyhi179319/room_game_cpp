#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "player.h"
#include "tunnel.h"
// creates random number
class new_random{
public:
    int high;
    int low;
    new_random(int High,int Low) {
        high = High;
        low = Low;
    }
    int Random(){
        return rand() % high + low;
    }
};

class rooms {
public:
    // rooms
    std::string room_north;
    std::string room_east;
    std::string room_south;
    std::string room_west;
    tunnel tunnel;
    // item generator
    std::string pickItemForRoom(int r){
        std::string arrayNum[5] = {"damage", "flashlight", "knife", "food","gun"};
        return arrayNum[r];
    }
    // picks item from generator
    std::string room_north_item(){
        new_random r(5,0);
        return pickItemForRoom(r.Random());
    }
    std::string room_east_item(){
        new_random r(5,0);
        return pickItemForRoom(r.Random());
    }
    std::string room_south_item(){
        new_random r(5,0);
        return pickItemForRoom(r.Random());
    }
    std::string room_west_item(){
        new_random r(5,0);
        return pickItemForRoom(r.Random());
    }
    // creates the rooms and tries to diverse items
    void createRooms(){
        std::srand(time(0));
        room_north = room_north_item();
        room_east = room_east_item();
        room_south = room_south_item();
        room_west  = room_west_item();
        // north
        if(room_north == room_east){room_north = room_north_item();}else if(room_north == room_south){
            room_north = room_north_item();
        }else if(room_north == room_west){room_north = room_north_item();}
        // east
        if(room_east == room_north){room_east = room_east_item();} else if(room_east == room_south){
            room_east = room_east_item();
        }else if(room_east == room_west){room_east = room_east_item();}
        // south
        if(room_south == room_north){room_south = room_south_item();}else if(room_south == room_east){
            room_south = room_south_item();
        }else if(room_south == room_west){room_south = room_south_item();}
        // west
        if(room_west == room_north){room_west = room_west_item();}else if(room_west == room_east){
            room_west = room_west_item();
        }else if(room_west == room_south){room_west = room_east_item();};
    }
    // gives a result based on the generated item
    std::string result(std::string item){
        if(item == "damage"){
            return "damage";
        } else if(item == "food"){
            return "food";
        } else if(item == "flashlight"){
            return "flashlight";
        } else if(item == "knife"){
            return "knife";
        }else if(item == "gun"){
            return "gun";
        }
    }
};
