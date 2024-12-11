/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	}
	else
		return (ft_memcpy(dest, src, n));
	return (dest);
}
