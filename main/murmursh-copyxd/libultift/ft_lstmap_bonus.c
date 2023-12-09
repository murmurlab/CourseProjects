/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:11:10 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 14:30:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
