#include<iostream>
#include<fstream>
#include<string>
#include<memory>
#include "engine.h"
#include "player.h"
#include "trainee.h"
#include "fighter.h"
using namespace std;
 


int main(){

    
    // Main menu
    cout<<"========== Welcome to the RPG-game! =========="<<endl;
    cout<< "1. New game" <<endl;
    cout<< "2. Load game" <<endl;
    cout<< "3. Exit" <<endl;
    cout<<"Please select a number from above (press ENTER to continue): ";
    int input;
    while(cin>>input){
        if(input<1 || input>3)
            cout<<"Invalid number! Please select again (press ENTER to continue): ";
        else
            break;
    }

    // Exit
    if(3 == input) {return 0;}

    unique_ptr<Engine> engine;      // Engine
    unique_ptr<Player> self;        // Player

    // New game
    if(1 == input){
        cout<<"Please set a character name: ";
        string name;
        cin>>name;
        engine = std::make_unique<Engine>(0);
        self = std::make_unique<Trainee>(name, "Trainee", 25, 10, 100, 100, 1);         // Start game with trainee
    }

    // Load game
    else if(2 == input){    
        engine = std::make_unique<Engine>(0);
        self = engine->load();
        cout<<"Load complete"<<endl;
    }


    // In-game loop
    bool UPGRADED = false;
    while(self->isAlive()){

        // cout<<"==========================================="<<endl;

        if(5 == self->level && !UPGRADED){
            cout<<"Level up to 5! Could upgrade your character! Please choose from below:"<<endl;
            cout<<"1. Fighter"<<endl;
            cout<<"2. Mage"<<endl;
            
            // Let user to choose their upgrade character
            int choice;
            cin>>choice;
            self = engine->upgradePlayer(self, choice);   // 照猫画虎（所以要传入self作为参数），然后把“虎”指针返回给原先的“猫”指针

            self->show_stat();
            UPGRADED = true;
        }

        cout<<"........................ What are you going to do next? ........................"<<endl;
        cout<<"1. Fight!" <<endl;
        cout<<"2. Show stat" <<endl;
        cout<<"3. Save" <<endl;
        cout<<"4. Exit"<<endl;
        cout<<"5. Rest" <<endl;
        cout<<"Please select a number from above (press ENTER to continue): ";
        cin>>input;

        switch(input){
        case 1: 
            engine->day_counter++;
            self->fight();
            break;
        case 2:
            self->show_stat();
            break;
        case 3:
            engine->save(engine, self);
        case 4:
            return 0;
        case 5:
            engine->day_counter++;
            self->rest();
            break;
        default:
            cout<<"Invalid input number!"<<endl;
        }
    }
    
    cout<<"==== Game over ===="<<endl;

    return 0;
}