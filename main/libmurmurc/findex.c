





#include "murmurlibc.h"

t_list	*findex(t_list *p, int f)
{
	int	i;

	i = 0;
	if (!p)
		return (NULL);
	while (i != f)
	{
		if (!p->next)
			return (NULL);
		p = p->next;
		i++;
	}
	return (p);
}
