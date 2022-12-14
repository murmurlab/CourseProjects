/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nan0bit <nan0bit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:44:37 by codespace         #+#    #+#             */
/*   Updated: 2022/12/14 20:08:51 by nan0bit          ###   ########.fr       */
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
			recurse(pp + 1 ,i, s, c, l);
			break ;
		}
		l++;
	}
	elm = malloc(sizeof(char) * (l + 1));
	*pp = elm;
	while (l-- && s[++i] != c)
		*elm++ = s[i];
	*elm = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	size_t	i;
	char	**pp;

	i = 0;
	n = 0;
	while (s[i])
		n += (s[i++] == c);
	pp = malloc(sizeof(char) * (n + 1));
	recurse(pp, i, s, c, 0);
	return (pp);
}

int	main(void)
{
	char	*str = " split me  split   meeeee ";
	char	chr = ' ';
	char	**ptr;
	ptr = ft_split(str, chr);
	printf("ptr[0]: %s\nptr[1]: %s\nptr[2]: %s\nptr[3]: %s\nptr[4]: %s\nptr[5]: %s\nptr[6]: %s\nptr[7]: %s\nptr[8]: %s\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8]);
}