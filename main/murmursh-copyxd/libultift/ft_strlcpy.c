/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <stddef.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = (size_t)ft_strlen(src);
	if (dstsize == 1 || !dstsize)
	{
		if (!dstsize)
			return (ret);
		*dst = 0;
		return (ret);
	}
	while ((dstsize-- - 1) && *src)
	{
		*dst++ = *src++;
	}
	*dst = 0;
	return (ret);
}
