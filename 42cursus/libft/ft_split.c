/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:44:37 by codespace         #+#    #+#             */
/*   Updated: 2022/12/15 04:29:18 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"








/* 
static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
 */















char	**ft_split(const char *s, char c)
{
	size_t	counter;
	size_t	elem_n;
	size_t	flag;

	counter = 0;
	elem_n = 0;
	while (s[counter])
	{
		if (s[counter] != c)
			flag = 1;
		else
			flag = 0;
		elem_n += ((s[++counter] != 0) && (s[counter] != c)
				&& (flag ^ (s[counter] != c)));
	}
	printf("elem_n: %zu\n", elem_n);
	return (0);
}




int	main(void)
{
	char	*str = "aaaa";
	char	chr = ' ';
	char	**ptr;
	ptr = ft_split(str, chr);
	printf("ptr[0]: %s\nptr[1]: %s\nptr[2]: %s\nptr[3]: %s\nptr[4]: %s\nptr[5]: %s\nptr[6]: %s\nptr[7]: %s\nptr[8]: %s\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8]);
}