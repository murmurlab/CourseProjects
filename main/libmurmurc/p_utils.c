





// ahbasara

#include "murmurlibc.h"

unsigned long long int	xp(unsigned long long int i, char *s, char m)
{
	unsigned long long int	digit;
	unsigned long long int	lne;
	char					base;

	base = qp(s, 0, 0);
	lne = 1;
	digit = 1;
	if (m && (long long int)i < 0)
	{
		write(1, "-", (lne++ || 1));
		i *= -1;
	}
	while ((digit * base) != 0 && (i / (digit * base)))
		digit *= (base * (lne++ || 1));
	while (digit && (i / digit || !i))
	{
		qp(NULL, 0, s[(i / digit) % base]);
		digit /= base;
	}
	return (lne);
}

unsigned long long int	qp(char *s, char p, char kar)
{
	unsigned long long int	i;

	i = 0;
	if (p && !s)
		return (write(1, "(null)", 6));
	while (s && s[i])
		write(1, &s[i++], p);
	return ((!s && write(1, &kar, (!s || 0))) + i);
}

void	check_format(va_list argl, const char **str, int *len)
{
	if ((**str) == 'c' && (*str)++)
		*len += qp(NULL, 0, va_arg(argl, int));
	else if ((**str) == 's' && (*str)++)
		*len += qp(va_arg(argl, char *), 1, 0);
	else if ((**str) == 'u' && (*str)++)
		*len += xp(va_arg(argl, unsigned int), "0123456789", 0);
	else if (((**str) == 'd' || (**str) == 'i' || (**str) == 'u') && (*str)++)
		*len += xp(va_arg(argl, int), "0123456789", 1);
	else if ((**str) == 'p' && (*str)++)
		*len += (qp("0x", 1, 0) + xp(va_arg(argl, unsigned long), \
		"0123456789abcdef", 0));
	else if ((**str) == 'x' && (*str)++)
		*len += xp(va_arg(argl, unsigned int), "0123456789abcdef", 0);
	else if ((**str) == 'X' && (*str)++)
		*len += xp(va_arg(argl, unsigned int), "0123456789ABCDEF", 0);
	else if ((**str) == '%' && (*str)++)
		*len += qp(NULL, 0, '%');
}
