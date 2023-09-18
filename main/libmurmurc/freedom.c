





#include "murmurlibc.h"

void	freedom(void **adr)
{
	if (adr)
	{
		free(*adr);
		*adr = 0;
	}
}
