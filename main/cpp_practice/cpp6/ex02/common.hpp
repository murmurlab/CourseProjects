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

# define stringify(str) stringify_(str)
# define stringify_(str) #str

// #include <sanitizer/lsan_interface.h>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <exception>

using std::exception;
using std::rand;
using std::srand;
using std::time;
using std::cout;
using std::endl;

#endif // COMMON_H
