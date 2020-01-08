// 1.Header Guard(file name + big random number)
#ifndef _MAGE_H_53532423484_
#define _MAGE_H_53532423484_

// 2.Header body
#include<string>
#include "trainee.h"
using namespace std;

class Mage: public Trainee{
public:
    Mage(string name, string type, int a, int d, int HP, int max_HP, int level)
        :Trainee(name, type, a, d, HP, max_HP, level) {}
    
    Mage(const std::unique_ptr<Player>& ptr)                 // Need to be const& ?
        :Trainee(ptr->name, "Mage", ptr->attack_point, ptr->defense_point, ptr->HP, ptr->maximum_HP, ptr->level) {}
};

#endif