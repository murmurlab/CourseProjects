





// ahbasara

#include "murmurlibc.h"

void	lladd(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = llend(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}
