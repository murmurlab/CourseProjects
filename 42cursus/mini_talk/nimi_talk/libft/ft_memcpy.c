/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:23:11 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/19 23:43:49 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*p;

	p = dst;
	while (n--)
		*(char *)(dst++) = *(char *)(src++);
	return (p);
}

/* int main()
{
	int i = 5;
	void *p1 = &i;
	printf("adrr: %p\n", p1);
	printf("adrr: %p\n", ++p1);
	char str[] = "abcdef";
	const int arr[] = {5, 3, 3, 7};
	void *v;
	v =ft_memcpy(str, arr, 4);
	printf("stock: %p\n", str);
	printf("return: %p\n", v);
	printf("str[0]: %d\nstr[1]: %d\nstr[2]: %d\nstr[3]: %d\nstr[4]:
	%d\nstr[5]: %d\n", str[0], str[1], str[2], str[3], str[4], str[5]);
} */
