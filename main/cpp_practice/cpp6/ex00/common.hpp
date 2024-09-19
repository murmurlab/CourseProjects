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

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include <sstream>
#include <exception>
#include <typeinfo>
#include <string>
#include <climits>
#include <limits>

using std::setw;
using std::cout;
using std::exception;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::string;

#endif // COMMON_H
