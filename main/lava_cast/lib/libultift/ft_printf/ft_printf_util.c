/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str != '\0')
	{
		if (ft_print_char((int) *str) == -1)
			return (-1);
		++count;
		++str;
	}
	return (count);
}

int	chain_result(int *count, int parser_result)
{
	if (parser_result == -1)
		return (1);
	else
	{
		*count += parser_result;
		return (0);
	}
}

int	ft_print_digit(long n, int base, int small_big)
{
	int		count;
	char	*symbols;
	char	*symbols_cap;

	symbols = "0123456789abcdef";
	symbols_cap = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_print_digit(-n, base, 0) + 1);
	}
	else if (n < base && small_big == 0)
		return (ft_print_char(symbols[n]));
	else if (n < base && small_big == 1)
		return (ft_print_char(symbols_cap[n]));
	else
	{
		if (chain_result(&count, ft_print_digit(n / base, base, small_big)) || \
			chain_result(&count, ft_print_digit(n % base, base, small_big)))
			return (-1);
		return (count);
	}
}

int	ft_print_digit2(unsigned long n, unsigned long base, int small_big)
{
	int		count;
	char	*symbols;
	char	*symbols_cap;

	symbols = "0123456789abcdef";
	symbols_cap = "0123456789ABCDEF";
	if (n < base && small_big == 0)
		return (ft_print_char(symbols[n]));
	else if (n < base && small_big == 1)
		return (ft_print_char(symbols_cap[n]));
	else
	{
		count = ft_print_digit(n / base, base, small_big);
		return (count + ft_print_digit(n % base, base, small_big));
	}
}
