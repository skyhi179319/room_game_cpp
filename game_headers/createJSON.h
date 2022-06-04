#include <iostream>
using namespace std;

class createJSON {
public:
    void createPlayer(std::string name,int coins){
        std::string q = "\"";
        std::string b = "{";
        std::string a = "}";
        std::string ab = "[";
        std::string aa = "]";
        std::string n = q + "name" + q + ":" + q + name + q;
        std::string co = q + "coins" + q + ":" + q + to_string(coins) + q;
        std::string j = b + q + "data" + q + ":" + ab + q + name + q + "," + q +to_string(coins) + q + aa + a;
        s.file.createFile(player_json,j);
    }
    void createRecord(int wins,int losses,int ties){
        std::string q = "\"";
        std::string b = "{";
        std::string a = "}";
        std::string win = to_string(wins);
        std::string loss = to_string(losses);
        std::string tie = to_string(ties);
        std::string w = q + "wins" + q + ":" + q + win + q;
        std::string l = q + "losses" + q + ":" + q + loss + q;
        std::string t = q + "ties" + q + ":" + q + tie + q;
        std::string j = b + w + "," + l + "," + t + a;
        s.file.createFile(record_json,j);
    }
private:
    sys s;
};
createJSON cj;