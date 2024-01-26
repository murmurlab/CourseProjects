/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:56:59 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/26 20:29:51 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_list	*lst_filter(t_list *nod, int f(t_list *node_iterate, void *data_compare), void *data)
{
	while (nod)
	{
        if (f(nod, data))
            return (nod);
		nod = nod->next;
	}
	return (NULL);
}

char	*ft_strsjoin(t_merge *strs[])
{
	void		*ret;
	char		*s;
	size_t		_;

	_ = 0;
	s = 0;
	while (strs[_])
		s += strs[_++]->len;
	if (!s)
		return (NULL);
	s = (ret = ft_calloc(sizeof(char), (size_t)s + 1));
	if (s == NULL)
		return (NULL);
	_ = 0;
	while (strs[_])
	  {
		if (strs[_]->str)
			while (strs[_]->len--)
				*s++ = *(strs[_]->str)++;
		_++;
	}
	return (ret);
}

int		strccmp(const char *s1, const char *s2, char ch)
{
	size_t			i;
	unsigned char	*one;
	unsigned char	*two;
	char			diff;

	i = 0;
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (one[i] || two[i])
	{
		if (one[i] != two[i])
		{
			diff = (one[i] - two[i]);
			if (diff == ch || diff == -ch)
				return (i);
			return (0);
		}
		i++;
	}
	return (0);
}

t_list	*lst_filter_prev(t_list *nod, int f(t_list *node_iterate, void *data_compare), void *data)
{
	t_list		*prev;
	
	prev = nod;
	while (nod)
	{
        if (f(nod, data))
            return (prev);
		prev = nod;
		nod = nod->next;
	}
	return (NULL);
}

size_t		arr2tolst(char **arr, t_list **lst)
{
	size_t		_;

	_ = 0;
	while (arr[_])
	{
		ft_lstadd_back(lst, ft_lstnew(arr[_]));
		_++;
	}
	return (_);
}