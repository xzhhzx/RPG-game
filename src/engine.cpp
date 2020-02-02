#include<iostream>
#include<fstream>
#include<string>
#include "engine.h"
#include "player.h"
#include "fighter.h"
#include "mage.h"
using namespace std;

Engine::Engine(int day_counter)
    :day_counter{day_counter} {}



/* Save game */
void Engine::save(const unique_ptr<Engine>& engine, const unique_ptr<Player>& self){
    cout<<"Input file name: ";
    string file_name;
    cin>>file_name;

    ofstream csv_table;                         // 1. Create file stream instance (locally on stack)
    csv_table.open("./saves/" + file_name);     // 2. Open file
    csv_table << engine->day_counter << ","             // 3. Write file
              << self->name << "," 
              << self->player_type << "," 
              << self->attack_point << ","
              << self->defense_point << ","
              << self->HP << "," 
              << self->maximum_HP << ","
              << self->level <<"\n";     
    csv_table.close();                          // 4. Close file
}



/* Load game */
std::unique_ptr<Player> Engine::load(){
    cout<<"Input file name: ";
    string file_name;
    cin>>file_name;

    ifstream csv_table;                         // 1. Create file stream instance (locally on stack)
    csv_table.open("./saves/" + file_name);     // 2. Open file
    string dc, name, player_type, ap, dp, HP, max_HP, level;
    csv_table >> dc >> name;                     // 3. Read file 
    cout << dc <<endl;                           // (have to split!)
    csv_table.close();                          // 4. Close file


    this->day_counter = 123;
    return this->createPlayer("zzz", "Mage", 100,20,30,40,6);

    // this->day_counter = std::stoi(dc);
    // return this->createPlayer(name, player_type, std::stoi(ap), std::stoi(dp), std::stoi(HP), std::stoi(max_HP), std::stoi(level));     // Return player
}



/* Use factory pattern to create player */
std::unique_ptr<Player> Engine::createPlayer(string name, string player_type, int ap, int dp, int HP, int max_HP, int level){
    
    if(player_type == "Trainee")
        return std::make_unique<Trainee>(name, player_type, ap, dp, HP, max_HP, level);
    else if(player_type == "Mage")
        return std::make_unique<Mage>(name, player_type, ap, dp, HP, max_HP, level);
    else if(player_type == "Fighter")
        return std::make_unique<Fighter>(name, player_type, ap, dp, HP, max_HP, level);  
    return nullptr;
}



/* Use factory pattern to upgrade player */
std::unique_ptr<Player> Engine::upgradePlayer(const unique_ptr<Player>& player_ptr, int choice){
    if(choice == 1)
        return std::make_unique<Fighter>(player_ptr);
    else if(choice == 2)
        return std::make_unique<Mage>(player_ptr);
    return nullptr;
}




// Helper function
// string serialize(string file_name, Player& p){
// 
// }