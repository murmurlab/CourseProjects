/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len);

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}
