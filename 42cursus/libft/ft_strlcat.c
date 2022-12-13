#include "libft.h"


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	i = 0;
	j = 0;
	while(dst[i])
		i++;
	while (src[j] && (dstsize - i) > 1 && dst[i])
		dst[i++] = src[j++];
	if ((size_t)(&dst[i] - dst) < dstsize)
		dst[i] = 0;
	if (dstsize < (size_t)(&dst[i] - dst))
		return (dstsize + (size_t)ft_strlen(src));
	return ( (&dst[i] - dst) + (size_t)ft_strlen(src));
}


/* 
size_t	ft_strlcat2(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
 */

int	main()
{
	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
	memset(dest, 'B', 4);

	//char dst[99] = "deneme12rr";
	//char src[99] = "testxyz";
	size_t l;
	printf("%ld\n", (l = ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA")));
	printf("text: %s\nlen: %zu\n", dest, l);
}
