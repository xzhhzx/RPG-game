#include<iostream>
#include<fstream>
#include<string>
#include "engine.h"
#include "player.h"
using namespace std;
 


// void fight(int& HP){
//     cout<<"Fighting!!!"<<endl;
//     HP -= 5;
// }

// void show_stat(){
//     cout<<"Player status:"<<endl;
// }

// void save(int HP, string name){

//     cout<<"Input file name: ";
//     string file_name;
//     cin>>file_name;

//     ofstream csv_table;         // 1. Create file stream instance (locally on stack)
//     csv_table.open(file_name);  // 2. Open file
//     // csv_table.write("Name,");
//     csv_table << "Name," << name << "\n"
//               << "HP," << HP <<"\n";
//     csv_table.close();
// }

// void load(){
//     cout<<"Input file name: ";
//     string file_name;
//     cin>>file_name;

//     ifstream csv_table;         // 1. Create file stream instance (locally on stack)
//     csv_table.open(file_name);  // 2. Open file
//     // csv_table.write("Name,");
//     string _, name, HP;
//     csv_table >> _ >> name;
//     cout << _ <<endl;
//     cout << name <<endl;
//     csv_table.close();
//     cin>>_;
// }



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


    Engine* engine;
    Player* self;

    // New game
    if(1 == input){
        cout<<"Please set a character name: ";
        string name;
        cin>>name;
        engine = new Engine(0);
        self = new Player(name, 25, 10, 100, 100);

    }

    // Load game
    else if(2 == input){
        Engine* engine = NULL;
        Player* self = NULL;
        cout<<engine<<endl;
        Engine::load(engine, self);

        cout<<"Load complete"<<endl;
        cout<<engine->day_counter<<endl;
        cout<<self->HP<<endl;
    }


    // In-game loop
    while(self->HP > 0){
        cout<<"Your HP is "<<self->HP<<", what are you going to do next?"<<endl;
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
            engine->save(self->name, self->HP, engine->day_counter);
        case 4:
            return 0;
        case 5:
            engine->day_counter++;
            self->rest();
        default:
            cout<<"Invalid input number!"<<endl;
        }
    }
    
    cout<<"==== Game over ===="<<endl;

    return 0;
}