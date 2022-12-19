/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:13:08 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/19 22:19:43 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    write(fd, ft_itoa(n), ft_strlen(ft_itoa(n)));
}
/* 
int	main(void)
{
    ft_putnbr_fd(5,1);
}
 */