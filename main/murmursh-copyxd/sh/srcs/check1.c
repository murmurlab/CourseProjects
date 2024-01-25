#include "include.h"

int			is_dollar(char *str)
{
	return (
		str[0] == '$' &&
		is_var(str[1])
	);
}

int			start_with(char *str, char c)
{
	return (
		*str == c
	);
}

int			end_with(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
		str++;
	return (
		*--str == c
	);
}

int	check(t_list *node, void *cmp)
{
	if (strccmp(node->content, cmp, '='))
		return (1);
	return (0);
}
