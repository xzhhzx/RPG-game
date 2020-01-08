#include<iostream>
#include<algorithm>
#include "player.h"
using namespace std;


Player::Player(string name, int a, int d, int HP, int max_HP, int level)
    :name{name}, attack_point{a}, defense_point{d}, HP{HP}, maximum_HP{max_HP}, level{level}
{
    
}

void Player::fight(){
    cout<<"Fighting!!! A Gobelin appears......"<<endl;
    Player* enermy = new Player("Gobelin", 13, 5, 50, 50, 1);       // Create enermy
    while(enermy->HP > 0 && this->HP > 0){              // Fight in rounds until one dies
        this->HP -= max(enermy->attack_point - this->defense_point, 0);
        enermy->HP -= max(this->attack_point - enermy->defense_point, 0);
    }
    // HP -= 5;

    if(this->HP > 0){
        level++;                  // 1. Gain a level
        attack_point += 3;        // 2. Improve stat
        defense_point += 2;
        maximum_HP += 5;
        cout<<"\nFight won! Statastic improved! ";
        show_stat();
        // return true;
    } 
    // else {
    //     cout<<"Game over!"<<endl;
    //     // return false;
    // }
}

void Player::show_stat(){
    cout<<"Player "<< this->name << " status:"<<endl;
    cout<<"Attack point: "<< attack_point <<endl;
    cout<<"Defense point: "<< defense_point <<endl;
    cout<<"HP: "<< HP << "/" << maximum_HP<<endl;
    cout<<"Level: "<<level<<endl;
}

void Player::rest(){
    cout<<"Resting..."<<endl;
    HP = maximum_HP;
}

bool Player::isAlive(){
    if(this->HP > 0)
        return true;
    return false;
}