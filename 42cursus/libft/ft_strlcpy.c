/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:30:08 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/13 16:31:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(LIBC_SCCS) && !defined(lint)
static char *rcsid = "$OpenBSD: strlcpy.c,v 1.4 1999/05/01 18:56:41 millert Exp $";
#endif /* LIBC_SCCS and not lint */
#include <sys/cdefs.h>

#include <sys/types.h>
#include <string.h>

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
size_t strlcpy(dst, src, siz)
	char *dst;
	const char *src;
	size_t siz;
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	/* Copy as many bytes as will fit */
	if (n != 0 && --n != 0) {
		do {
			if ((*d++ = *s++) == 0)
				break;
		} while (--n != 0);
	}

	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0) {
		if (siz != 0)
			*d = '\0';		/* NUL-terminate dst */
		while (*s++)
			;
	}

	return(s - src - 1);	/* count does not include NUL */
}






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
	printf("dst0[0]: %d, dst0[1]: %d, dst0[2]: %d, dst0[3]: %d, dst0[4]: %d, dst0[5]: %d, dst0[6]: %d, dst0[7]: %d\n", dst0[0], dst0[1], dst0[2], dst0[3], dst0[4], dst0[5], dst0[6], dst0[7]);
	printf("dst1[0]: %d, dst1[1]: %d, dst1[2]: %d, dst1[3]: %d, dst1[4]: %d, dst1[5]: %d, dst0[6]: %d, dst0[7]: %d\n", dst1[0], dst1[1], dst1[2], dst1[3], dst1[4], dst1[5], dst1[6], dst1[7]);
}
 */