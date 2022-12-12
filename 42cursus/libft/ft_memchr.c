/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:29:13 by codespace         #+#    #+#             */
/*   Updated: 2022/12/11 14:48:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- && *(char *)s && *(unsigned char *)s != (unsigned char)c)
		s++;
	if (*(unsigned char *)s == (unsigned char)c && ++n)
		return ((void *)s);
	return (NULL);
}
/* 
int	main(void)
{
	int find = 200;
	unsigned const char arr[] = {200 , 'q', 'a', 's', 'd', 'f'};
	void *vp;
	vp = ft_memchr(arr, find, 9);
	printf("locate first-> %p\n", arr);
	printf("locate find -> %p\n", vp);
}
 */