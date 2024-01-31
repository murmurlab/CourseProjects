/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

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
