/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <sys/_types/_null.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (char)c)
			return ((char *)s - 1);
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
