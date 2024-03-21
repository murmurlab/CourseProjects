#include "ScavTrap.hpp"

ScavTrap::ScavTrap(string name_c): ClapTrap(name_c){
cout    << "ScavTrap " << name << " is spawned." << endl;
}

ScavTrap::~ScavTrap(){
cout    << "ScavTrap " << name << " is disappeared." << endl;
}

void ScavTrap::guardGate(){
cout    << "ScavTrap is now in Gate keeper mode." << endl;
}