





// ahbasara

#include "murmurlibc.h"

size_t	strclen(const char *s, char c)
{
	size_t	r;

	r = 0;
	while ((((*s == c) && r++) || 1) && *s++)
		;
	return (r);
}
/* 
int	main(void)
{
	size_t s;
	char *arr = "cekoslavakyalilastiramadiklarimizdanmistircasina";

	s = strclen(arr, 'a');
	p("%d\n", s);
}
 */
