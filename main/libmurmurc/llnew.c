// ahbasara

#include "murmurlibc.h"

t_list	*llnew(void *content)
{
	t_list	*elt;

	elt = (t_list *)malloc(sizeof(t_list));
	if (elt == NULL)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}

/*
int	main(void)
{
	struct s_list	*list;
	char	*str = "Hello";

	list = ft_lstnew("aaaa");
	list->content = str;
	printf("'list' value: %s\n", (char *)list->content);
}
*/
