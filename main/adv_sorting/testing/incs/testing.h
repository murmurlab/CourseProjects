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

# include <stdio.h>
# include <time.h>
# include <stdlib.h>

# include "include.h"

int     tablen(char **tab);
void	print_links(void *iter, void *data);
char    **file_load(char *path);
int     print_stacks(t_stacks *stacks);


#endif
