/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <stdlib.h>

char	*ft_strdup(const char *s1);

static void	ft_recursive(int nb, char *str)
{
	if (nb >= 10)
	{
		ft_recursive(nb / 10, str - 1);
		*str = ((nb % 10) + 48);
	}
	if (nb < 10)
		*str = (nb + 48);
}

char	*ft_itoa(int nb)
{
	char	*str;
	char	digit;
	char	*ostr;
	int		n;
	int		stat;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	stat = (nb < 0);
	n = nb;
	digit = 2;
	if (stat)
		n *= -1 + (digit++ && 0);
	while (10 <= n)
		n /= 10 + (digit++ && 0);
	str = malloc(sizeof(char) * digit);
	if (!str)
		return (NULL);
	ostr = str;
	(void)(stat && (*str++ = '-', 1) && (nb *= -1));
	*(str + ((sizeof(char) * digit) - 1 - stat)) = 0;
	ft_recursive(nb, (str + ((sizeof(char) * digit) - 2 - stat)));
	return (ostr);
}
