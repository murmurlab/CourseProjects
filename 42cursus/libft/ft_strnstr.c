/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:33:22 by codespace         #+#    #+#             */
/*   Updated: 2022/12/12 01:53:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)strstr.c	8.1 (Berkeley) 6/4/93";
#endif /* LIBC_SCCS and not lint */
#include <sys/cdefs.h>

#include <string.h>

/*
 * Find the first occurrence of find in s, where the search is limited to the
 * first slen characters of s.
 */

char *
strnstr(s, find, slen)
	const char *s;
	const char *find;
	size_t slen;
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}


#include "libft.h"

char	*strnstr_spirnaz(const char *haystack, const char *needle, size_t len)
{
	size_t index;
	size_t jndex;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	index = 0;
	jndex = 0;
	while (1)
	{
		if (needle[jndex] == '\0')
			return ((char *)(haystack + (index - jndex)));
		if (haystack[index] == needle[jndex])
			jndex++;
		else
		{
			index -= jndex;
			jndex = 0;
		}
		if (haystack[index] == '\0' || index >= len)
			return (NULL);
		index++;
	}
}


#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p;

	while ((*needle || ((p = (char *)haystack) && 0)) && (p = (char *)needle)
		&& ((*haystack && len-- && *needle && (*haystack == *needle
					|| haystack++)) || (p = 0)))
	{
		while ((len && *haystack == *needle && ((haystack++ && needle++)
					&& len--)) || ((needle = p) && 0))
		{
			if ((!*needle) && (needle = p))
				return ((char *)haystack - 0 - 0 - 0 - ft_strlen(needle));
		}
	}
	return (p);
}

int	main(void)
{
	char	*haystack = "i searchinneedleg needle in the haystack";
	char	*needle = "needle";
	size_t	l = 19;
	printf("out: %s\n", ft_strnstr(haystack, needle, l));
	printf("out: %s\n", strnstr(haystack, needle, l));
	printf("out: %s\n", strnstr_spirnaz(haystack, needle, l));
	
}
