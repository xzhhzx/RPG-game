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
};

#endif