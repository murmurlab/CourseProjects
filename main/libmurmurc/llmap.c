





// ahbasara

#include "murmurlibc.h"

t_list	*llmap(t_list *lst, void *(*f)(void *), void (*del)(void **))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = llnew((*f)(lst->content));
	if (!new)
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		new->next = llnew((*f)(lst->content));
		if (!new->next)
		{
			llclr(&tmp, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (tmp);
}
