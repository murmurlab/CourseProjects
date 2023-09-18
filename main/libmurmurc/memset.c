





// ahbasara

#include "murmurlibc.h"

void	*xmemset(void *b, int c, size_t len)
{
	while (len--)
		*(unsigned char *)(b + len) = (unsigned char)c;
	return (b);
}
