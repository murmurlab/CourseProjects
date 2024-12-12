#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H
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
#include "IMateriaSource.hpp"

#define MAX_COUNT_OF_MATERIA 4

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class AMateria;

class MateriaSource: public IMateriaSource
{
private:
    int idx;
    AMateria *slot[MAX_COUNT_OF_MATERIA];
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(IMateriaSource &copy);
    IMateriaSource &operator=(IMateriaSource &to_assign);

    void learnMateria(AMateria *);
    AMateria* createMateria(string const & type);
};

#endif
