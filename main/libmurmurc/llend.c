





// ahbasara

#include "murmurlibc.h"

t_list	*llend(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/* {
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
} */
