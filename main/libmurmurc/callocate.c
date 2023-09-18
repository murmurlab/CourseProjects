// ahbasara

#include "murmurlibc.h"

void
	*callocate(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	memnull(ptr, count * size);
	return (ptr);
}
