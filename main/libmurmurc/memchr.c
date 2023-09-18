





// ahbasara

#include "murmurlibc.h"

void	*memchr(const void *s, int c, size_t n)
{
	while (n-- && *(unsigned char *)s != (unsigned char)c)
		s++;
	if (*(unsigned char *)s == (unsigned char)c && ++n)
		return ((void *)s);
	return (NULL);
}

/* int	main(void)
{
	int find = 2;
	unsigned const char arr[] = {0, 1, 2 ,3 ,4 ,5};
	void *vp;
	vp = ft_memchr(arr, find, 3);
	printf("locate first-> %p\n", arr);
	printf("locate find -> %p\n", vp);
} */
