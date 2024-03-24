#include "Animal.hpp"

Animal::Animal()
{
}

Animal::~Animal()
{
}
Animal::Animal(Animal &copy){    
*this = copy;
cout    << "ClapTrap copy constructor called" << endl;
}

Animal &Animal::operator=(Animal &assignment){
this->name = assignment.name;
this->health = assignment.health;
this->energy = assignment.energy;
this->damage = assignment.damage;
cout    << "ClapTrap copy assignment operator called" << endl;
return *this;
}