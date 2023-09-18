





// ahbasara

#include "murmurlibc.h"

char	*stradd(char const *s1, const char *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = xstrlen(s1) + xstrlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	xstrlcpy(str, s1, xstrlen(s1) + 1);
	xstrlcat(str, s2, xstrlen(s1) + xstrlen(s2) + 1);
	return (str);
}
