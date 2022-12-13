/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:52:32 by codespace         #+#    #+#             */
/*   Updated: 2022/12/12 17:51:58 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n-- && *s1 && *s2 )
	{
		s1++;
		s2++;
	}
	if (!n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/* int	main(void)
{
	char	*kedy = "whEreareyoucatx";
	char	*kedi = "whereareyoucat";

	printf("diff: %d\n", ft_strncmp(kedy, kedi, 2));
} */
