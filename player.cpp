#include<iostream>
#include "player.h"
using namespace std;


Player::Player(string name, int a, int d, int HP, int max_HP)
    :name{name}, attack_point{a}, defense_point{d}, HP{HP}, maximum_HP{max_HP}
{
    
}

void Player::fight(){
    cout<<"Fighting!!!"<<endl;
    HP -= 5;
}

void Player::show_stat(){
    cout<<"Player "<< this->name << " status:"<<endl;
    cout<<"Attack point: "<< attack_point <<endl;
    cout<<"Defense point: "<< defense_point <<endl;
    cout<<"HP: "<< HP << "/" << maximum_HP<<endl;
}

void Player::rest(){
    cout<<"Resting..."<<endl;
    HP = maximum_HP;
}