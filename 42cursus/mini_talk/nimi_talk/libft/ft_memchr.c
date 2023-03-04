/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:29:13 by codespace         #+#    #+#             */
/*   Updated: 2022/12/12 17:38:16 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- && *(unsigned char *)s != (unsigned char)c)
		s++;
	if (*(unsigned char *)s == (unsigned char)c && ++n)
		return ((void *)s);
	return (NULL);
}

/* int	main(void)
{
	int find = 2;
	unsigned const char arr[] = {0, 1, 2 ,3 ,4 ,5};
	void *vp;
	vp = ft_memchr(arr, find, 3);
	printf("locate first-> %p\n", arr);
	printf("locate find -> %p\n", vp);
} */
