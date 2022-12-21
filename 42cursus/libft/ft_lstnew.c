/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:58:45 by codespace         #+#    #+#             */
/*   Updated: 2022/12/21 00:22:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elt;

	elt = (t_list *)malloc(sizeof(*elt));
	if (elt == NULL)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}

int	main(void)
{
	struct s_list	*list;
	char	*str = "Hello";

	list = ft_lstnew("Hello");
	list->content = str;
	t_list->constent = str;
	printf("'list' value: %s\n", (char *)list->content);
	printf("'t_list' value: %s\n", (char *)t_list->content);
}