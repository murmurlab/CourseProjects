#ifndef SCAVTRAP_H
# define SCAVTRAP_H
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
#include "ClapTrap.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class ScavTrap : public ClapTrap
{
private:
    ScavTrap();
public:
    ScavTrap(string name_c);
    ~ScavTrap();

    void attack(const string& target);
    void guardGate( void );
};



#endif
