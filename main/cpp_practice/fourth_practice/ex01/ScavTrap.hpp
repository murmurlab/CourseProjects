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

class ScavTrap : ClapTrap
{
private:
    string  name;
    int     health;
    int     energy;
    int     damage;
public:
    ScavTrap(string name_c);
    ScavTrap(ScavTrap &copy);
    ScavTrap &operator=(ScavTrap &assignment);
    ~ScavTrap();
    void attack(const string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void guardGate( void );
};



#endif
