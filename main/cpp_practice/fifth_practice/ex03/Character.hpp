#ifndef CHARACTER_H
# define CHARACTER_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

# endif

# define RED				"\x1B[31m"
# define GREEN				"\x1B[32m"
# define YELLOW				"\x1B[33m"
# define BLUE				"\x1B[34m"
# define RESET				"\x1B[0m"

#include <iostream>
#include "ICharacter.hpp"

#define MAX_COUNT_OF_MATERIA 4

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Character : public ICharacter
{
private:
    AMateria *slot[MAX_COUNT_OF_MATERIA];
    string name;
    Character();
public:
    Character(Character &copy);
    ~Character( void );
    Character &operator=(Character &to_assign);

    Character(string name);
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};


#endif
