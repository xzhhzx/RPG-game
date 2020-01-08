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
    Engine(int day_counter);       // Initialize a new game
    void save(string name, int HP, int day_count);
    static void load(Engine* e, Player* p);
    // static void load(Engine& e, Player& p);
    std::unique_ptr<Player> createPlayer(const unique_ptr<Player>& player_ptr, int choice);
};


#endif