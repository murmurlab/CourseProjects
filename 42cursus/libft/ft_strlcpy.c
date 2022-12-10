/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:30:08 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/10 15:46:36 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t ret;
	
	ret = (size_t)ft_strlen(dst) + (size_t)ft_strlen(src);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = 0;
	return (ret);
}
/* 
int main()
{
	char dst[99] = "destination";
	const char src[99] = "source";
	
	printf("return: %lu\n", ft_strlcpy(dst, src, 3));
	printf("dst: %s\n", dst);
}
 */