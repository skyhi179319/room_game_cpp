#include <iostream>
#include "headers/sys.h"
#include "game_headers//game.h"
#include "game_headers//damage.h"
#include "game_headers//scoring.h"
#include "game_headers/store.h"
using namespace std;

int main() {
    bool game_use = true;
    // system
    sys s;
    // game functions
    game gm;
    // coins call
    coins c;
    // store call
    store store;
    store.setPrices();
    // user info
    std::string firstname,lastname;
    s.createLine(70);
    s.log("program");
    s.createLine(70);
    s.input.input_text("please enter first, then last name");
    s.createLine(70);
    std::string firstname_in =  s.input.user_input(firstname);
    std::string lastname_in =  s.input.user_input(lastname);
    // creating a line
    s.createLine(70);
    // player class
    player p(firstname_in,lastname_in);
    // loading chances
    if(s.file.dirExist("filesystem")){
        if(s.file.exist(wins_file)){
            int wins = s.convert.convertFromString(s.file.readFile(wins_file));
            p.chances.wins = wins;
        }else{
            s.file.createFile(wins_file, to_string(0));
            int wins = s.convert.convertFromString(s.file.readFile(wins_file));
            p.chances.wins = wins;
        }
        if(s.file.exist(losses_file)){
            int losses = s.convert.convertFromString(s.file.readFile(losses_file));
            p.chances.losses = losses;
        }else{
            s.file.createFile(losses_file, to_string(0));
            int losses = s.convert.convertFromString(s.file.readFile(losses_file));
            p.chances.losses = losses;
        }
        if(s.file.exist(ties_files)){
            int ties = s.convert.convertFromString(s.file.readFile(ties_files));
            p.chances.ties = ties;
        }else{
            s.file.createFile(ties_files, to_string(0));
            int ties = s.convert.convertFromString(s.file.readFile(ties_files));
            p.chances.ties = ties;
        }
    }
    else{
        s.file.mkDir("filesystem");
        if(s.file.exist(wins_file)){
            int wins = s.convert.convertFromString(s.file.readFile(wins_file));
            p.chances.wins = wins;
        }else{
            s.file.createFile(wins_file, to_string(0));
            int wins = s.convert.convertFromString(s.file.readFile(wins_file));
            p.chances.wins = wins;
        }
        if(s.file.exist(losses_file)){
            int losses = s.convert.convertFromString(s.file.readFile(losses_file));
            p.chances.losses = losses;
        }else{
            s.file.createFile(losses_file, to_string(0));
            int losses = s.convert.convertFromString(s.file.readFile(losses_file));
            p.chances.losses = losses;
        }
        if(s.file.exist(ties_files)){
            int ties = s.convert.convertFromString(s.file.readFile(ties_files));
            p.chances.ties = ties;
        }else{
            s.file.createFile(ties_files, to_string(0));
            int ties = s.convert.convertFromString(s.file.readFile(ties_files));
            p.chances.ties = ties;
        }
    }
    // console logging player info
    s.log(p.firstname + "," + p.lastname);
    // creating a line
    s.createLine(70);
    // setting mode
    std::string mode;
    s.input.input_text("select either |easy|hard|");
    s.createLine(70);
    std::string mode_in = s.input.user_input(mode);
    weapons w(mode_in);
    // creating a line
    s.createLine(70);
    // creates room;
    gm.r.createRooms();
    std::string room_array[4] = {gm.r.room_north,gm.r.room_east,gm.r.room_south,gm.r.room_west};
    s.printArray(room_array);
    // creating a line
    s.createLine(70);
    // plays game while health is above 0
    while (p.getHealth() > 0 && game_use == true) {
        std::string input;
        s.input.input_text("Please select either |north|east|south|west|tunnel|store|stats|");
        s.createLine(70);
        std::string input_in = s.input.user_input(input);
        // logging input for testing
        s.createLine(70);
        s.log(input_in);
        s.createLine(70);
        if(input_in == before_user_input + "north"){
            if(gm.r.result(gm.r.room_north) == "damage"){p.minusHealth();
            }else if(gm.r.result(gm.r.room_north) == "food"){p.addHealth();
            }else if(gm.r.result(gm.r.room_north) == "flashlight"){p.addFlashlight();
            }else if(gm.r.result(gm.r.room_north) == "knife"){p.addKnife();}
            else if(gm.r.result(gm.r.room_north) == "gun"){p.addGun();}
            std::string stats = "player health " + to_string(p.getHealth());
            s.log(stats);
            s.createLine(70);
        } else if(input_in == before_user_input + "east"){
            if(gm.r.result(gm.r.room_east) == "damage"){p.minusHealth();
            }else if(gm.r.result(gm.r.room_east) == "food"){p.addHealth();
            }else if(gm.r.result(gm.r.room_east) == "flashlight"){p.addFlashlight();
            }else if(gm.r.result(gm.r.room_east) == "knife"){p.addKnife();}
            else if(gm.r.result(gm.r.room_east) == "gun"){p.addGun();}
            std::string stats = "player health " + to_string(p.getHealth());
            s.log(stats);
            s.createLine(70);
        } else if(input_in == before_user_input + "south"){
            if(gm.r.result(gm.r.room_south) == "damage"){p.minusHealth();
            }else if(gm.r.result(gm.r.room_south) == "food"){p.addHealth();
            }else if(gm.r.result(gm.r.room_south) == "flashlight"){p.addFlashlight();
            }else if(gm.r.result(gm.r.room_south) == "knife"){p.addKnife();}
            else if(gm.r.result(gm.r.room_south) == "gun"){p.addGun();}
            std::string stats = "player health " + to_string(p.getHealth());
            s.log(stats);
            s.createLine(70);
        } else if(input_in == before_user_input + "west"){
            if(gm.r.result(gm.r.room_west) == "damage"){p.minusHealth();
            }else if(gm.r.result(gm.r.room_west) == "food"){p.addHealth();
            }else if(gm.r.result(gm.r.room_west) == "flashlight"){p.addFlashlight();
            }else if(gm.r.result(gm.r.room_west) == "knife"){p.addKnife();}
            else if(gm.r.result(gm.r.room_west) == "gun"){p.addGun();}
            std::string stats = "player health " + to_string(p.getHealth());
            s.log(stats);
            s.createLine(70);
        }else if(input_in == before_user_input + "tunnel"){
            if(p.items.knife == false || p.items.flashlight == false){
                p.minusHealth();
                std::string player_stats = "player health: " + to_string(p.getHealth());
                s.log(player_stats);
                s.createLine(70);
                s.log("can't go in tunnel without the flashlight and knife");
                s.createLine(70);
            }
            else{
                if(gm.r.tunnel.b.getHealth() > 0){
                    new_random nr(50,5);
                    damage d;
                    // already know knife is true
                    if(p.items.gun == true){
                        // another user input
                        std::string boss_input;
                        s.input.input_text("pick either |knife|gun|");
                        s.createLine(70);
                        std::string boss_input_in = s.input.user_input( boss_input);
                        s.createLine(70);
                        if(boss_input_in == before_user_input + "knife"){
                            if(p.items.twoTimesMultiplier == true){
                                gm.r.tunnel.simulate_boss(d.do_damage(w.knife,nr.Random()) * 2);
                                c.add(gm.r.tunnel.b.returnLastDamage() * 2);
                            }
                            else{
                                gm.r.tunnel.simulate_boss(d.do_damage(w.knife,nr.Random()));
                                c.add(gm.r.tunnel.b.returnLastDamage());
                            }
                            p.simulate(d.do_damage(w.spear,nr.Random()));
                        }
                        else if(boss_input_in == before_user_input + "gun"){
                            if(p.items.twoTimesMultiplier == true){
                                gm.r.tunnel.simulate_boss(d.do_damage(w.gun,nr.Random()) * 2);
                                c.add(gm.r.tunnel.b.returnLastDamage() * 2);
                            }
                            else{
                                gm.r.tunnel.simulate_boss(d.do_damage(w.gun,nr.Random()));
                                c.add(gm.r.tunnel.b.returnLastDamage());
                            }
                            p.simulate(d.do_damage(w.spear,nr.Random()));
                        }
                    }
                    else{
                        if(p.items.twoTimesMultiplier == true){
                            gm.r.tunnel.simulate_boss(d.do_damage(w.knife,nr.Random()) * 2);
                            c.add(gm.r.tunnel.b.returnLastDamage() * 2);
                        }
                        else{
                            gm.r.tunnel.simulate_boss(d.do_damage(w.knife,nr.Random()));
                            c.add(gm.r.tunnel.b.returnLastDamage());
                        }
                        p.simulate(d.do_damage(w.spear,nr.Random()));
                    }
                    std::string boss_stats = "boss health: " + to_string(gm.r.tunnel.b.getHealth());
                    std::string player_stats = "player health: " + to_string(p.getHealth());
                    s.log(boss_stats);
                    s.createLine(70);
                    s.log(player_stats);
                    s.createLine(70);
                    if(gm.r.tunnel.b.getHealth() == 0){
                        game_use = false;
                    }
                } else{
                    // for debugging purposes
                    s.log("Already defeated boss");
                }
            }
        }else if (input_in == before_user_input + "store"){
            s.log("Coins: " + to_string(c.amount));
            s.createLine(70);
            std::string store_input;
            s.input.input_text("please pick either health|multiplier|");
            s.createLine(70);
            std::string store_input_in = s.input.user_input(store_input);
            if(store_input_in == before_user_input + "health"){
                if(c.buy(store.prices.tenHealth) == true){
                    p.addHealth(10);
                    s.createLine(70);
                }
                else{
                    s.log("can't buy health");
                    s.createLine(70);
                }
            }else if(store_input_in == before_user_input + "multiplier"){
                if(c.buy(store.prices.twoTimesMultiplier) == true){
                    p.addMultiplier();
                    s.createLine(70);
                }
                else{
                    s.createLine(70);
                    s.log("can't buy multiplier");
                    s.createLine(70);
                }
            }else{
                s.log("ERROR: invalid response");
                s.createLine(70);
            }
        }else if(input_in == before_user_input + "stats"){
            s.log("Current coins: " + to_string(c.amount));
            s.createLine(70);
            s.log("Last Damage: " + to_string(gm.r.tunnel.b.returnLastDamage()));
            s.createLine(70);
            std::string record = to_string(p.chances.wins) + "-" + to_string(p.chances.losses) +
                    "-" + to_string(p.chances.ties);
            s.log("Record: " + record);
            s.createLine(70);
        }
        else{
            s.log("ERROR: invalid response");
            s.createLine(70);
        }
    }
    scoring score(p.getHealth(),p.items.gun,mode_in);
    s.log(to_string(score.returnTotal()));
    s.createLine(70);
    if(s.file.dirExist("filesystem")){
        if(s.file.exist(coins_file)){
            s.file.deleteFile(coins_file);
            int total_coins = c.amount;
            s.file.createFile(coins_file, to_string(total_coins));
        }else{
            int total_coins = c.amount;
            s.file.createFile(coins_file, to_string(total_coins));
        }
        // write condition statements for each outcome
        if(s.file.exist(wins_file)){
            s.file.deleteFile(wins_file);
            if(p.getHealth() > 0){
                s.file.createFile(wins_file, to_string(p.chances.wins + 1));
            }
        }else{
            if(p.getHealth() > 0){
                s.file.createFile(wins_file, to_string(p.chances.wins + 1));
            }
        }
        if(s.file.exist(losses_file)){
            s.file.deleteFile(losses_file);
            if(p.getHealth() == 0){
                s.file.createFile(losses_file, to_string(p.chances.losses + 1));
            }
        }else{
            if(p.getHealth() == 0){
                s.file.createFile(losses_file, to_string(p.chances.losses + 1));
            }
        }
        if(s.file.exist(ties_files)){
            s.file.deleteFile(ties_files);
            if(p.getHealth() == 0 && gm.r.tunnel.b.getHealth() == 0){
                s.file.createFile(ties_files, to_string(p.chances.ties + 1));
            }
        }else{
            if(p.getHealth() == 0 && gm.r.tunnel.b.getHealth() == 0){
                s.file.createFile(ties_files, to_string(p.chances.ties + 1));
            }
        }
    }
    else{
        s.file.mkDir("filesystem");
        if(s.file.exist(coins_file)){
            s.file.deleteFile(coins_file);
            int total_coins = c.amount;
            s.file.createFile(coins_file, to_string(total_coins));
        }else{
            int total_coins = c.amount;
            s.file.createFile(coins_file, to_string(total_coins));
        }
        if(s.file.exist(wins_file)){
            s.file.deleteFile(wins_file);
            if(p.getHealth() > 0){
                s.file.createFile(wins_file, to_string(p.chances.wins + 1));
            }
        }else{
            if(p.getHealth() > 0){
                s.file.createFile(wins_file, to_string(p.chances.wins + 1));
            }
        }
        if(s.file.exist(losses_file)){
            s.file.deleteFile(losses_file);
            if(p.getHealth() == 0){
                s.file.createFile(losses_file, to_string(p.chances.losses + 1));
            }
        }else{
            if(p.getHealth() == 0){
                s.file.createFile(losses_file, to_string(p.chances.losses + 1));
            }
        }
        if(s.file.exist(ties_files)){
            s.file.deleteFile(ties_files);
            if(p.getHealth() == 0 && gm.r.tunnel.b.getHealth() == 0){
                s.file.createFile(ties_files, to_string(p.chances.ties + 1));
            }
        }else{
            if(p.getHealth() == 0 && gm.r.tunnel.b.getHealth() == 0){
                s.file.createFile(ties_files, to_string(p.chances.ties + 1));
            }
        }
    }
    // terminate program
    return 0;
}