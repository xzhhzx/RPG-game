// 1.Header Guard(file name + big random number)
#ifndef _TRAINEE_H_532972999621_
#define _TRAINEE_H_532972999621_

// 2.Header body
#include<string>
#include "player.h"
using namespace std;

class Trainee: public Player{

public:
    Trainee(string name, string type, int a, int d, int HP, int max_HP, int level)
        :Player(name, type, a, d, HP, max_HP, level) {

            cout<<"+.+.+.+.+.+.+.+. Trainee constructor +.+.+.+.+.+.+.+."<<endl;
        }
};

#endif