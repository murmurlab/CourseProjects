





// ahbasara

#include "murmurlibc.h"

void	recursive(int nb, char *str)
{
	if (nb >= 10)
	{
		recursive(nb / 10, str - 1);
		*str = ((nb % 10) + 48);
	}
	if (nb < 10)
		*str = (nb + 48);
}

char	*xstrcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*x_itoa(int nb)
{
	char	*str;
	char	digit;
	char	*ostr;
	int		n;
	int		stat;

	stat = (nb < 0);
	n = nb;
	digit = 2;
	if (stat)
		n *= -1 + (digit++ && 0);
	while (10 <= n)
		n /= 10 + (digit++ && 0);
	str = malloc(sizeof(char) * digit);
	ostr = str;
	if (nb == -2147483648)
		return (xstrcpy(str, "-2147483648"));
	if (stat)
	{
		*str++ = '-';
		nb *= -1;
	}
	*(str + ((sizeof(char) * digit) - 1 - stat)) = 0;
	recursive(nb, (str + ((sizeof(char) * digit) - 2 - stat)));
	return (ostr);
}

/* int	main(void)
{
	printf("res: %s\n", ft_itoa(-1234));
} */
