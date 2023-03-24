/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:42:09 by codespace         #+#    #+#             */
/*   Updated: 2022/12/21 15:22:08 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
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
