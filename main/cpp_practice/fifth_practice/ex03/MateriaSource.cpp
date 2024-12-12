#include "AMateria.hpp"
#include "MateriaSource.hpp"

void    MateriaSource::learnMateria(AMateria *to_learn) {
    if (this->idx == 4) return ;
    slot[this->idx] = to_learn; 
    // cout << "slot learning: \n";
    // cout << "to_learn> " << to_learn->getType() << endl;
    // cout << "slot> " << slot[this->idx]->getType() << endl;
    this->idx++;
}

AMateria *MateriaSource::createMateria(string const & type) {
    for (int i = 0; i < this->idx; i++)
        if (slot[i]->getType() == type) return slot[i]->clone();
    return NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < this->idx; i++)
        if (slot[i]) delete slot[i];
}

MateriaSource::MateriaSource(): idx(0) {
    
}