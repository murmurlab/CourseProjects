/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:58:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 03:49:29 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_striter_error(char *s, int (*f)(unsigned int, char*, void *), void *pp)
{
	unsigned int	i;

	i = 0;
	if (!(*s) || !f)
		return (1);
	while (s[i])
	{
		if (f(i, &s[i], pp))
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t	r;

	r = 0;
	while ((((*s == c) && r++) || 1) && *s++)
		;
	return (r);
}

int	ft_strsome(char *s, int (*f)(unsigned int, char *, void *), void *pass)
{
	unsigned int	i;

	i = 0;
	if (!(*s) || !f)
		return (0);
	while (s[i])
	{
		if (f(i, &s[i], pass))
			return (1);
		i++;
	}
	return (0);
}

int	ft_strevery(char *s, int (*f)(unsigned int, char *, void *), void *pass)
{
	unsigned int	i;

	i = 0;
	if (!(*s) || !f)
		return (0);
	while (s[i])
	{
		if (!f(i, &s[i], pass))
			return (1);
		i++;
	}
	return (0);
}

t_list	*findex(t_list *p, int f)
{
	int	i;

	i = 0;
	if (!p)
		return (NULL);
	while (i != f)
	{
		if (!p->next)
			return (NULL);
		p = p->next;
		i++;
	}
	return (p);
}
