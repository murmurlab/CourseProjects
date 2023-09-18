





// ahbasara

#include "murmurlibc.h"

int	xmemcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

/* {
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && n--)
	{
		s1++;
		s2++;
	}
	if (!n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
} */
/*
int	main(void)
{
	char	*kedy = "whereareyoucatx";
	char	*kedi = "whereareyoucat";
	size_t	l = 25;

	printf("my  diff: %d\n", ft_memcmp(kedy, kedi, l));
	printf("our diff: %d\n", memcmp(kedy, kedi, l));

}
 */
