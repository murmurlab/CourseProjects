#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(string name) : name(name) {
    this->slot[0] = 0;
    this->slot[1] = 0;
    this->slot[2] = 0;
    this->slot[3] = 0;
}

Character::Character(Character &copy) :
    name(copy.name) {
    this->slot[0] = 0;
    this->slot[1] = 0;
    this->slot[2] = 0;
    this->slot[3] = 0;
    *this = copy;
}

Character &Character::operator=(Character &to_assign) {
    for (size_t i = 0; i < MAX_COUNT_OF_MATERIA; i++) {
        if (this->slot[i]){
            delete this->slot[i];
        }
    }
    this->slot[0] = to_assign.slot[0]->clone();
    this->slot[1] = to_assign.slot[1]->clone();
    this->slot[2] = to_assign.slot[2]->clone();
    this->slot[3] = to_assign.slot[3]->clone();
    this->name = to_assign.name;
    return *this;
}

Character::~Character( void ) {
    for (size_t i = 0; i < MAX_COUNT_OF_MATERIA; i++) {
        if (this->slot[i]){
            delete this->slot[i];
        }
    }
}

string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
    for (size_t i = 0; i < MAX_COUNT_OF_MATERIA; i++) {
        if (!this->slot[i]){
            this->slot[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
	if (this->slot[idx]) {
        this->slot[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
	if (this->slot[idx]) {
        this->slot[idx]->use(target);
        // delete this->slot[idx];
    }
}