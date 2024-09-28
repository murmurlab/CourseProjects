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
// # define ft_size(type, variable) sizeof(variable) / sizeof(type)


// #include <sanitizer/lsan_interface.h>
# include <iostream>
# include <cstddef>

using std::size_t;
using std::cout;
using std::string;
using std::endl;


template<typename T, size_t N>
size_t ft_size2(T (&)[N]) { return N; }



#endif // COMMON_H
