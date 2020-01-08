#include<iostream>
#include<fstream>
#include<string>
#include "engine.h"
#include "player.h"
#include "fighter.h"
#include "mage.h"
using namespace std;

Engine::Engine(int day_counter)
    :day_counter{day_counter}
{

}


void Engine::save(string name, int HP, int day_count){
    cout<<"Input file name: ";
    string file_name;
    cin>>file_name;

    ofstream csv_table;         // 1. Create file stream instance (locally on stack)
    csv_table.open("./saves/" + file_name);  // 2. Open file
    csv_table << name << "," << HP << "," << day_count <<"\n";     // 3. Write file
    csv_table.close();                          // 4. Close file
}

void Engine::load(Engine* e, Player* p){
    cout<<e<<endl;
    cout<<"Input file name: ";
    string file_name;
    cin>>file_name;

    ifstream csv_table;         // 1. Create file stream instance (locally on stack)
    csv_table.open("./saves/" + file_name);  // 2. Open file
    string _, name, HP;
    csv_table >> _ >> name;     // 3. Read file (have to split!)
    cout << _ <<endl;
    // cout << name <<endl;
    csv_table.close();          // 4. Close file

    // e = new Engine(day_counter);
    // p = new Player(name, a, d, HP, max_HP);    
    // e = new Engine(18);
    // p = new Player("Zihan", 25, 10, 17, 100,1);

    cout<<e->day_counter<<endl;
    cout<<p->HP<<endl;
    cout<<e<<endl;                  // ('e' had changed!)
    cout<<"Return"<<endl;
    return;
}


std::unique_ptr<Player> Engine::createPlayer(const unique_ptr<Player>& player_ptr, int choice){

    if(choice == 1){
        cout<<"Choice is 1"<<endl;
        return std::make_unique<Fighter>(player_ptr);
    }
    else if(choice == 2){
        return std::make_unique<Mage>(player_ptr);
    }
    
    return NULL;
}

// Helper function
// string serialize(string file_name, Player& p){
// 
// }