/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:21:21 by codespace         #+#    #+#             */
/*   Updated: 2022/12/11 02:48:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
	}
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	return (NULL);
}
/* 
int	main(void)
{
	char	f = 'n';
	char	*s = "nopestringmenoob!";
	if ((ft_strrchr(s, f)))
	{
		printf("char: %p\n", (ft_strchr(s, f)));
		printf("char: %p\n", (ft_strrchr(s, f)));
	}
}
 */