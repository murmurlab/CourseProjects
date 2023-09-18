





// ahbasara

#include "murmurlibc.h"

void	llclr(t_list **lst, void (*del)(void **))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		lldel(lst, del);
		*lst = tmp;
	}
}
