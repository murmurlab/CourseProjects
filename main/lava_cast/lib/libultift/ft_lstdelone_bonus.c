/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <malloc/_malloc.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
		(*del)(lst->content);
	if (lst)
		free(lst);
}
