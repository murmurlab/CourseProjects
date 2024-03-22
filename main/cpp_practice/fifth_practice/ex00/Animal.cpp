#include "Animal.hpp"

Animal::Animal()
{
}

Animal::~Animal()
{
}
ClapTrap::ClapTrap(ClapTrap &copy){    
*this = copy;
cout    << "ClapTrap copy constructor called" << endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &assignment){
this->name = assignment.name;
this->health = assignment.health;
this->energy = assignment.energy;
this->damage = assignment.damage;
cout    << "ClapTrap copy assignment operator called" << endl;
return *this;
}