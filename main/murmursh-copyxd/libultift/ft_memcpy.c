/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <sys/_types/_size_t.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*p;

	p = dst;
	if (!dst && !src && n)
		return (dst);
	while (n--)
		*(char *)(dst++) = *(char *)(src++);
	return (p);
}
