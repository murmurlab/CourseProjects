#include "./HumanB.hpp"

void HumanB::attack(){
cout<< name << " attacks with their " << (weapon ? weapon->getType() : string("NONE")) <<endl;
}

HumanB::HumanB(string given_name){
weapon = nullptr;
name = given_name;
}

void HumanB::setWeapon(Weapon &given_weapon){
weapon = &given_weapon;
}
