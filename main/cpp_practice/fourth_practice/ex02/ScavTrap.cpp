#include "ScavTrap.hpp"

ScavTrap::ScavTrap(string name_c): ClapTrap(name_c){
health = 100;
energy = 50;
damage = 20;
cout    << "ScavTrap " << name << " is spawned." << endl;
}

void ScavTrap::attack(const string &target){
if (health <= 0){
    cout    << "ScavTrap " << name << " is dead." << endl;
    return;
}
if (energy <= 0){
    cout    << "ScavTrap " << name << " is not have energy." << endl;
    return ;
}
cout    << "ScavTrap " << name << " attacks " << target << ", causing "
        << damage << " points of damage!" << endl;
energy--;
if (energy == 0){
    cout    << "ScavTrap " << name << "'s energy is over." << endl;
}
}

ScavTrap::~ScavTrap(){
cout    << "ScavTrap " << name << " is disappeared." << endl;
}

void ScavTrap::guardGate(){
cout    << "ScavTrap is now in Gate keeper mode." << endl;
}