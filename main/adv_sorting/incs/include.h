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
#  define BIGGER_THAN_PIVOT 128
#  define REVERSE 1
# endif

# include "murmurlibc.h"

typedef struct s_stacks
{
	t_link	stack_a;
	t_link	stack_b;
	char	buff;
	int		multi;
}		t_stacks;

typedef struct s_utils
{
	char		*op;
	char		arr[4];
	t_link		*stack;
	int			flag;
	long		len;
	long		direction;
	char		c;
}		t_utils;

typedef struct s_sort
{
	int			a_b[3];
	int			pvt[2];
	int			pivot;
	int			op;
	int			abs;
	int			abs_b;
	int			argc;
	t_stacks	*stacks
}		t_sort;

# include "testing.h"

int		check_sort(t_link stack, int size);
void	del(void **tab);
void	load_nums(int ac, char **av, t_stacks *stacks, int sort_cntl);
double	ft_fabs(register double x);

#endif
