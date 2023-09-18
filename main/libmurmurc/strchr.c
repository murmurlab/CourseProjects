





// ahbasara

#include "murmurlibc.h"

char	*xstrchr(const char *s, int c)
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
/* 
int	main(void)
{
	char	f = 'g';
	char	*s = "stringme!";
	if ((ft_strchr(s, f)))
		printf("char: %c\n", *(ft_strchr(s, f)));
}
 */
