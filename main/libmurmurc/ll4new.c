





// ahbasara

#include "murmurlibc.h"

t_wasd	*ll4new(void *content)
{
	t_wasd	*elt;

	elt = (t_wasd *)malloc(sizeof(t_wasd));
	if (elt == NULL)
		return (NULL);
	elt->i = content;
	elt->prev = NULL;
	elt->ww = NULL;
	elt->aa = NULL;
	elt->ss = NULL;
	elt->dd = NULL;
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
