/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <sys/_types/_null.h>
#include <malloc/_malloc.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*head;
	void	*v;

	head = NULL;
	if (lst && del && f)
	{
		while (lst)
		{
			v = f(lst->content);
			t = (t_list *)malloc(sizeof(t_list));
			if (!t)
			{
				ft_lstclear(&head, del);
				free(v);
				return (NULL);
			}
			t->content = v;
			t->next = NULL;
			ft_lstadd_back(&head, t);
			lst = lst->next;
		}
	}
	return (head);
}
