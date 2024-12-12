#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure( void ) : AMateria("cure") {

}

Cure::~Cure( void ) {

}

Cure::Cure(Cure &copy): AMateria("cure") {
    *this = copy;
}

Cure &Cure::operator=(Cure &to_assign) {
    this->type = to_assign.getType();
    return *this;
}
void Cure::use(ICharacter &target) {
    (void)target;
    cout << "* heals " << target.getName() << "’s wounds *" << endl;
}

AMateria *Cure::clone( void ) const {
    return new Cure();
}
