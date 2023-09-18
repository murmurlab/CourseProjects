





// ahbasara

#include "murmurlibc.h"

int	p(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			check_format(args, &str, &len);
		}
		else
			len += qp(NULL, 0, *(str++));
	}
	va_end(args);
	return (len);
}

/* int	main(void)
{
	ft_printf("Hello World! %d", 0);
	return (0);
} */
