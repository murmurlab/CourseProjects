





// ahbasara

#include "murmurlibc.h"

size_t	xstrlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}
/* 
int	main(void)
{
	size_t s;
	char *arr = "faruk";

	s = ft_strlen(arr);
	printf("%zu\n", s);
}
 */
