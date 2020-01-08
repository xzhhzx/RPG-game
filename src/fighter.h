// 1.Header Guard(file name + big random number)
#ifndef _FIGHTER_H_53297573605184_
#define _FIGHTER_H_53297573605184_

// 2.Header body
#include<string>
#include "trainee.h"
using namespace std;

class Fighter: public Trainee{
public:
    Fighter(string name, string type, int a, int d, int HP, int max_HP, int level)
        :Trainee(name, type, a, d, HP, max_HP, level) {}
    
    Fighter(const std::unique_ptr<Player>& ptr)                 // Need to be const& ?
        :Trainee(ptr->name, "Fighter", ptr->attack_point, ptr->defense_point, ptr->HP, ptr->maximum_HP, ptr->level) {}
    
};

#endif