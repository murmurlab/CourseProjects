/* 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
 */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	while(dst[i])
		i++;
	while ((int)(dstsize - i) > 1)
		dst[i++] = *src++;
	if ((size_t)(&dst[i] - dst) < dstsize)
		dst[i] = 0;
	if (dstsize < (size_t)(&dst[i] - dst))
		return (dstsize + (size_t)ft_strlen(src));
	return ( (&dst[i] - dst) + (size_t)ft_strlen(src));
}
/* int	main()
{
	char dst[99] = "deneme12rr";
	char src[99] = "testxyz";
	size_t l;
	l = strlcat(dst, src, 7);
	printf("text: %s\nlen: %zu\n", dst, l);
} */