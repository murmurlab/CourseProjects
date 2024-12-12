#include "AMateria.hpp"

class Cure: public AMateria
{
public:
    Cure( void );
    ~Cure( void );
    Cure(Cure &copy);
    Cure &operator=(Cure &to_assign);

    AMateria *clone() const;
    void use(ICharacter &target);
};
