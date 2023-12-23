#ifndef TESTING_H
# define TESTING_H
# if defined(__linux__)
	/* Linux. --------------------------------------------------- */
// #  include "./linux.h"
	/* WSL keycodes */
/* #  define W 119
#  define A 97
#  define S 115
#  define D 100 */

# elif defined(__APPLE__)
	/* OSX. --------------------------------------------------- */
/* #  include "./apple.h"
#  define W 13
#  define A 0
#  define S 1
#  define D 2 */

# endif

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

# define VAR "0000"
# define VAR_LEN 4

# ifndef TEST
#  define TEST 0
# endif

# include "include.h"

struct s_tests;

typedef struct s_test
{
	size_t			test_number;
	t_list			*fails;
	t_list			*success;
	void			(*ko_msg)(struct s_tests *test);
	void			(*ok_msg)(struct s_tests *test);

	struct s_tests	*tests;
	void			*my_data;
}				t_test;

struct s_try;

typedef struct s_tests
{
	char			*name;
	int				(*test_fun)(t_test *test);
	struct s_try	*trys;
}				t_tests;

typedef struct s_try
{
	void	*try;
	void	*expected;
}				t_try;

void run_test();

#endif
