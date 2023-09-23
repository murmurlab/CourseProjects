#ifndef INCLUDE_H
# define INCLUDE_H
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

# include "../murmurlibc/murmurlibc.h"

typedef struct s_stacks
{
	t_link	stack_a;
	t_link	stack_b;
}		t_stacks;

void     del(void **tab);

#endif
