/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:06:59 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/10 17:00:32 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{	
	if (dest > src)
	{
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	}
	else
		return (ft_memcpy(dest, src, n));
	return (dest);
}
