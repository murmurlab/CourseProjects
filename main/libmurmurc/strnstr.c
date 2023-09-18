





// ahbasara

#include "murmurlibc.h"

char	*strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		position;

	if (*to_find == '\0')
		return ((char *)str);
	position = xstrlen((char *)to_find);
	while (*str != '\0' && len-- >= position)
	{
		if (*str == *to_find && xmemcmp(str, to_find, position) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
