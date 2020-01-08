// 1.Header Guard(file name + big random number)
#ifndef _PLAYER_H_5342579804_
#define _PLAYER_H_5342579804_

// 2.Header body
#include<string>
using namespace std;

class Player{

public:
    const string name;
    string player_type;
    int attack_point;
    int defense_point;
    int HP;
    int maximum_HP;
    int level;

public:    
    Player(string name, string type, int a, int d, int HP, int max_HP, int level);
    void fight();
    void show_stat();
    void rest();
    bool isAlive();
};

#endif