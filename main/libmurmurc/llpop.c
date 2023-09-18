





// ahbasara

#include "murmurlibc.h"

void	llpop(t_list **lst, void (*del)(void **))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	if (lst && *lst)
	{
		tmp = (*lst)->next;
		lldel(lst, del);
		*lst = tmp;
	}
}
