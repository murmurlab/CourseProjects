/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <stddef.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
	}
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	return (NULL);
}
