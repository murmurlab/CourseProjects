





// ahbasara

#include "murmurlibc.h"

void	lldel(t_list **lst, void (*del)(void **))
{
	if (!del)
		return ;
	if (*lst)
	{
		(*del)(&(*lst)->content);
		free(*lst);
	}
}
