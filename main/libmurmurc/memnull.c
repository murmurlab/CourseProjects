





// ahbasara

#include "murmurlibc.h"

void
	memnull(void *s, size_t n)
{
	while (n-- > 0)
	{
		*(char *)(s + n) = 0;
	}
	return ;
}
