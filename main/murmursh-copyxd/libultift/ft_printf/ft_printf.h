/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:11:10 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 14:30:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
int		ft_printf_options(char specifier, va_list args);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_digit(long n, int base, int a);
int		ft_print_p(void *data);
int		ft_print_digit2(unsigned long n, unsigned long base, int small_big);

#endif
