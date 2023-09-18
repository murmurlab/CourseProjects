





// ahbasara

#include "murmurlibc.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	}
	else
		return (xmemcpy(dest, src, n));
	return (dest);
}
