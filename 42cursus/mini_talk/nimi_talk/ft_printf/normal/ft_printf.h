/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:31:30 by hece              #+#    #+#             */
/*   Updated: 2023/01/14 13:03:10 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

unsigned long long int	x(unsigned long long int i, char *s, char m);
unsigned long long int	q(char *s, char p, char kar);
void					ft_check_format(va_list argl, \
							const char **str, int *len);
int						ft_printf(const char *str, ...);

#endif
