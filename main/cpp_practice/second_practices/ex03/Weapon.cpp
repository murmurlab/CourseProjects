#include "./Weapon.hpp"

const string    &Weapon::getType(){
return type;
}

void            Weapon::setType(string given_type){
type = given_type;
}

Weapon::Weapon(string given_type){
type = given_type;
}

Weapon::Weapon(){}