#include "AMateria.hpp"

class Ice: public AMateria
{
public:
    Ice( void );
    ~Ice( void );
    Ice(Ice &copy);
    Ice &operator=(Ice &to_assign);

    AMateria *clone() const;
    void use(ICharacter &target);
};