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

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_free(char **tab, int count)
{
	while (count >= 0)
	{
		free(tab[count]);
		count--;
	}
	free(tab);
	return (0);
}

static char	*ft_cpy_wrd(char const *s, char *tab, int i, int lg)
{
	int	j;

	j = 0;
	while (lg > 0)
	{
		tab[j] = s[i - lg];
		lg--;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static char	**count_lenght(char const *s, char c, char **tab, int count)
{
	int	lg;
	int	i;
	int	w;

	i = 0;
	lg = 0;
	w = 0;
	while (w < count)
	{
		lg = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			lg++;
			i++;
		}
		tab[w] = malloc(lg + 1);
		if (!tab[w])
			return (ft_free(tab, w));
		ft_cpy_wrd(s, tab[w], i, lg);
		w++;
	}
	tab[w] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;

	if (!s)
		return (0);
	count = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab = count_lenght(s, c, tab, count);
	return (tab);
}
