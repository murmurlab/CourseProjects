#include "FragTrap.hpp"

FragTrap::FragTrap(string name_c): ClapTrap(name_c){
health = 100;
energy = 100;
damage = 30;
cout    << "FragTrap " << name << " is spawned." << endl;
}

FragTrap::~FragTrap(){
cout    << "FragTrap " << name << " is disappeared." << endl;
}

void FragTrap::highFivesGuys( void ){
cout    << "FragTrap " << name << " is requested a positive high fives." << endl;
}