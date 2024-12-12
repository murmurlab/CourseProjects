#ifndef AMATERIA_H
# define AMATERIA_H
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

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class ICharacter;

class AMateria
{
protected:
    string type;
private:
    AMateria( void );
    AMateria(AMateria &copy);
    AMateria &operator=(AMateria &to_assign);

public:
    virtual ~AMateria( void );

    AMateria(string const &type);
    string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif
