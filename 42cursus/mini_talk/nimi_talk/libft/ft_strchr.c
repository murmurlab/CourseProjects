/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 01:27:38 by codespace         #+#    #+#             */
/*   Updated: 2022/12/11 02:48:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (char)c)
			return ((char *)s - 1);
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/* 
int	main(void)
{
	char	f = 'g';
	char	*s = "stringme!";
	if ((ft_strchr(s, f)))
		printf("char: %c\n", *(ft_strchr(s, f)));
}
 */