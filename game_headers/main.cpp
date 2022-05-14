#include <iostream>
#include "headers/sys.h"
#include "game_headers//game.h"
#include "game_headers//damage.h"
using namespace std;

int main() {
    bool game_use = true;
    // system
    sys s;
    // game functions
    game gm;
    // user info
    std::string firstname,lastname;
    s.log("program");
    s.input.input_text("please enter first, then last name");
    std::string firstname_in =  s.input.user_input(firstname);
    std::string lastname_in =  s.input.user_input(lastname);
    // player class
    player p(firstname_in,lastname_in);
    // console logging player info
    s.log(p.firstname + "," + p.lastname);
    // creates room;
    gm.r.createRooms();
    s.log(gm.r.room_north);
    s.log(gm.r.room_east);
    s.log(gm.r.room_south);
    s.log(gm.r.room_west);
    // plays game while health is above 0
    while (p.getHealth() > 0 && game_use == true) {
        std::string input;
        s.input.input_text("Please select either north,east,south,west,tunnel");
        std::string input_in = s.input.user_input(input);
        // logging input for testing
        s.log(input_in);
        if(input_in == before_user_input + "north"){
            if(gm.r.result(gm.r.room_north) == "damage"){p.minusHealth();
            }else if(gm.r.result(gm.r.room_north) == "food"){p.addHealth();
            }else if(gm.r.result(gm.r.room_north) == "flashlight"){p.addFlashlight();
            }else if(gm.r.result(gm.r.room_north) == "knife"){p.addKnife();}
            else if(gm.r.result(gm.r.room_north) == "gun"){p.addGun();}
            std::string stats = "player health " + to_string(p.getHealth());
            s.log(stats);
        } else if(input_in == before_user_input + "east"){
            if(gm.r.result(gm.r.room_east) == "damage"){p.minusHealth();
            }else if(gm.r.result(gm.r.room_east) == "food"){p.addHealth();
            }else if(gm.r.result(gm.r.room_east) == "flashlight"){p.addFlashlight();
            }else if(gm.r.result(gm.r.room_east) == "knife"){p.addKnife();}
            else if(gm.r.result(gm.r.room_east) == "gun"){p.addGun();}
            std::string stats = "player health " + to_string(p.getHealth());
            s.log(stats);
        } else if(input_in == before_user_input + "south"){
            if(gm.r.result(gm.r.room_south) == "damage"){p.minusHealth();
            }else if(gm.r.result(gm.r.room_south) == "food"){p.addHealth();
            }else if(gm.r.result(gm.r.room_south) == "flashlight"){p.addFlashlight();
            }else if(gm.r.result(gm.r.room_south) == "knife"){p.addKnife();}
            else if(gm.r.result(gm.r.room_south) == "gun"){p.addGun();}
            std::string stats = "player health " + to_string(p.getHealth());
            s.log(stats);
        } else if(input_in == before_user_input + "west"){
            if(gm.r.result(gm.r.room_west) == "damage"){p.minusHealth();
            }else if(gm.r.result(gm.r.room_west) == "food"){p.addHealth();
            }else if(gm.r.result(gm.r.room_west) == "flashlight"){p.addFlashlight();
            }else if(gm.r.result(gm.r.room_west) == "knife"){p.addKnife();}
            else if(gm.r.result(gm.r.room_west) == "gun"){p.addGun();}
            std::string stats = "player health " + to_string(p.getHealth());
            s.log(stats);
        }else if(input_in == before_user_input + "tunnel"){
            if(p.items.knife == false || p.items.flashlight == false){
                p.minusHealth();
                std::string player_stats = "player health: " + to_string(p.getHealth());
                s.log(player_stats);
                s.log("can't go in tunnel without the flashlight and knife");
            }
            else{
                if(gm.r.tunnel.b.getHealth() > 0){
                    new_random nr(50,5);
                    damage d;
                    weapons w;
                    // already know knife is true
                    if(p.items.gun == true){
                        // another user input
                        std::string boss_input;
                        s.input.input_text("pick either knife or gun");
                        std::string boss_input_in = s.input.user_input(boss_input);
                        if(boss_input_in == before_user_input + "knife"){
                            gm.r.tunnel.simulate_boss(d.do_damage(w.knife,nr.Random()));
                            p.simulate(nr.Random());
                        }
                        else if(boss_input_in == before_user_input + "gun"){
                            gm.r.tunnel.simulate_boss(d.do_damage(w.gun,nr.Random()));
                            p.simulate(nr.Random());
                        }
                    }
                    else{
                        gm.r.tunnel.simulate_boss(d.do_damage(w.knife,nr.Random()));
                        p.simulate(nr.Random());
                    }
                    std::string boss_stats = "boss health: " + to_string(gm.r.tunnel.b.getHealth());
                    std::string player_stats = "player health: " + to_string(p.getHealth());
                    s.log(boss_stats);
                    s.log(player_stats);
                    if(gm.r.tunnel.b.getHealth() == 0){
                        game_use = false;
                    }
                } else{
                    // for debugging purposes
                    s.log("Already defeated boss");
                }
            }
        }
        else{
            // kills player for invalid response
            s.log("ERROR: invalid response - killed player");
            p.setHealth(0);
            game_use = false;
        }
    }
    // terminate program
    return 0;
}