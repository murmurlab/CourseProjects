#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice( void ) : AMateria("ice") {
    // cout << "Ice default constructor: " << this->getType() << endl;
}

Ice::~Ice( void ) {

}

Ice::Ice(Ice &copy): AMateria("ice") {
    *this = copy;
}

Ice &Ice::operator=(Ice &to_assign) {
    this->type = to_assign.getType();
    return *this;
}

void Ice::use(ICharacter &target) {
    (void)target;
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}

AMateria *Ice::clone( void ) const {
    return new Ice();
}
