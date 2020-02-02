// 1.Header Guard
#ifndef _ENGINE_H_13005285590659_
#define _ENGINE_H_13005285590659_

// 2.Header body
#include<iostream>
#include<memory>
#include "player.h"
using namespace std;

class Engine{
public:
    int day_counter;

public:
    // Engine(){};
    Engine(int day_counter);       // Initialize a new game
    void save(const unique_ptr<Engine>& engine, const unique_ptr<Player>& self);
    std::unique_ptr<Player> load();
    // static void load(Engine& e, Player& p);
    std::unique_ptr<Player> upgradePlayer(const unique_ptr<Player>& player_ptr, int choice);
    std::unique_ptr<Player> createPlayer(string name, string player_type, int ap, int dp, int HP, int max_HP, int level);
};


#endif