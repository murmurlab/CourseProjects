





// ahbasara

#include "murmurlibc.h"

void	llprepend(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
	}
}

/*
int	main(void)
{
	t_list	*list;
	char	*str = "Hello";

	list = ft_lstnew(str);
	printf("1st: %s\n", (char *)list->content);
	ft_lstadd_front(&list, ft_lstnew("aaaa"));
	printf("1st: %s\n", (char *)list->next->content);

}
*/
