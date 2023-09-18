





// ahbasara

#include "murmurlibc.h"

char	*strrchr(const char *s, int c)
{
	size_t	len;

	len = xstrlen(s);
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
	}
	if ((char)c == '\0')
		return ((char *)(s + xstrlen(s)));
	return (NULL);
}
/* 
int	main(void)
{
	char	f = 'n';
	char	*s = "nopestringmenoob!";
	if ((ft_strrchr(s, f)))
	{
		printf("char: %p\n", (ft_strchr(s, f)));
		printf("char: %p\n", (ft_strrchr(s, f)));
	}
}
 */
