/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:36:33 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/09 13:25:12 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define UTILS_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ctf(char *strinnnnng, unsigned long long int offset);
int		ft_printf(const char *s, ...);
size_t	ft_putstr(char *s, char p, char kar);

#endif