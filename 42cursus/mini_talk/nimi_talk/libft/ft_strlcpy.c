/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:30:08 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/19 23:07:33 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* 
int	main(void)
{
	char		dst0[] = {'0', '0', '0', '0', 0, '0', '0'};
	const char	src0[] = {'9', '9', '9', '9', '9', 0, '9', '9'};
	char		dst1[] = {'0', '0', '0', '0', 0, '0', '0'};
	const char	src1[] = {'9', '9', '9', '9', '9', 0, '9', '9'};

	printf("return0: %lu dst0: %s\n", ft_strlcpy(dst0, src0, 0), dst0);
	printf("return1: %lu dst1: %s\n", strlcpy(dst1, src1, 0), dst1);
	printf("dst0[0]: %d, dst0[1]: %d, dst0[2]: %d, dst0[3]: %d, dst0[4]: %d,
	dst0[5]: %d, dst0[6]: %d, dst0[7]: %d\n", dst0[0], dst0[1], dst0[2], dst0[3],
	dst0[4], dst0[5], dst0[6], dst0[7]);
	printf("dst1[0]: %d, dst1[1]: %d, dst1[2]: %d, dst1[3]: %d, dst1[4]: %d,
	dst1[5]: %d, dst0[6]: %d, dst0[7]: %d\n", dst1[0], dst1[1], dst1[2], dst1[3],
	dst1[4], dst1[5], dst1[6], dst1[7]);
}
 */