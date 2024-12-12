#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(string const &type) {
	this->type = type;
}

std::string const &AMateria::getType() const {
	// cout << "virtual AMateria::getType(): " << this->type << " ";
	return this->type;
}

AMateria::~AMateria( void ) {

}

AMateria::AMateria( void ) {

}

AMateria::AMateria(AMateria &copy) {
	*this = copy;
}

AMateria &AMateria::operator=(AMateria &to_assign) {
	this->type = to_assign.type;
	return *this;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}
