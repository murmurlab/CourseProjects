/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:44:37 by codespace         #+#    #+#             */
/*   Updated: 2022/12/14 07:57:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recurse(char	**pp, size_t i, const char *s, char c, size_t l)
{
	char	*elm;
	
	l = 0;
	while (i)
	{
		if (s[--i] == c)
		{
			recurse(pp++ ,i, s, c, l);
			break;
		}
		l++;
	}
	elm = malloc(sizeof(char) * (l + 1));
	*pp = elm;
	while (l-- && s[i] != c)
		*elm++ = s[i++];
	*elm = 0;
}

char **ft_split(char const *s, char c)
{
		// " split  split me    splitt.  "
		// 'split' '' 'split' 'me' '' '' '' 'splitt.' '' ''
		size_t n;
		size_t i;
		char	**pp;
		
		i = 0;
		while (s[i])
			n =+ (s[i++] == c);
		malloc(sizeof(char) * (n + 1));
		recurse(pp , i, s, c, 0);
		return (pp);
}