#if !defined(COMMON_H)
# define COMMON_H

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

# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iostream>
# include <exception>

using std::srand;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::exception;
using std::cout;
using std::ostream;
using std::cerr;
using std::endl;
using std::string;

#endif // COMMON_H
