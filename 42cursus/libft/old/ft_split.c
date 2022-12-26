/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:44:37 by codespace         #+#    #+#             */
/*   Updated: 2022/12/19 23:04:23 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_arr(const char *s, char **pp, size_t x, char c)
{
	const char	*tmp;
	char		*buff;
	const char	*stock;

	stock = s;
	tmp = 0;
	while (stock + x >= s)
	{
		if ((*s == c || *s == 0) && tmp)
		{
			buff = malloc(sizeof(char) * ((s - tmp) + 1));
			ft_strlcpy(buff, tmp, ((s - tmp) + 1));
			printf("add: %p\n", buff);
			*pp++ = buff;
			tmp = 0;
		}
		if (*s != c)
		{
			if (!tmp)
				tmp = s;
		}
		s++;
	}
}

char	**ft_split(const char *s, char c)
{
	size_t	counter;
	size_t	elem_n;
	char	flag;
	char	**pp;

	counter = -1;
	elem_n = 0;
	flag = 0;
	while (s[++counter])
	{
		elem_n += ((s[counter] != 0) && (s[counter] != c)
				&& (flag ^ (s[counter] != c)));
		if (s[counter] != c)
			flag = 1;
		else
			flag = 0;
	}
	pp = malloc(sizeof(char *) * (elem_n + 1));
	pp[elem_n] = 0;
	push_arr(s, pp, counter, c);
	printf("elem_n: %zu\n", elem_n);
	return (pp);
}

/* int	main(void)
{
	char	*str = "  tripouille  42 ";
	char	chr = ' ';
	char	**ptr;
	ptr = ft_split(str, chr);
	printf("ptr[0]: %s\nptr[1]: %s\nptr[2]: %s\nptr[3]: %s\nptr[4]:
	
	
	%s\nptr[5]: %s\nptr[6]: %s\nptr[7]: %s\nptr[8]: %s\n", ptr[0], ptr[1],
	
	ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8]);
} */