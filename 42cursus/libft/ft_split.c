/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:44:37 by codespace         #+#    #+#             */
/*   Updated: 2022/12/15 03:47:36 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	recurse(char	**pp, size_t i, const char *s, char c, size_t l)
{
	char	*elm;

	l = 0;
	while (i)
	{
		if (s[--i] == c)
		{
			recurse(pp + 1, i, s, c, l);
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
	recurse(pp + 7, i, s, c, 0);
	return (pp);
} */




/* 


static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

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

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
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


/* 

static size_t	ft_toklen(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_toklen(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}
 */



char	**ft_split(const char *s, char c)
{
	size_t	counter;
	size_t	elem_n;
	size_t	flag;

	i = 0;
	elem_n = 0;
	while (s[i])
	{
		if (s[i] != c)
			flag = 1;
		else
			flag = 0;
		elem_n =+ (flag ^ (s[++i] != c))
	}
	printf("elem_n: %d\n", elem_n);
	
}




int	main(void)
{
	char	*str = " split me  split   meeeee ";
	char	chr = ' ';
	char	**ptr;
	ptr = ft_split(str, chr);
	printf("ptr[0]: %s\nptr[1]: %s\nptr[2]: %s\nptr[3]: %s\nptr[4]: %s\nptr[5]: %s\nptr[6]: %s\nptr[7]: %s\nptr[8]: %s\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8]);
}