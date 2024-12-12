#include "./HumanA.hpp"

void HumanA::attack(){
cout<< name << " attacks with their " << weapon.getType() <<endl;
}

HumanA::HumanA(string given_name, Weapon &given_weapon): weapon(given_weapon.getType()){
name = given_name;
weapon = given_weapon;
}