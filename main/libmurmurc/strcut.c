





// ahbasara

#include "murmurlibc.h"

char	*strcut(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start)
		{
			if (j < len)
				str[j++] = s[i];
			else
				break ;
		}
	}
	str[j] = 0;
	return (str);
}

/* {
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
} */

/* int	main(void)
{
	printf("val: %p", ft_substr("ahmetf", -1, 3));
} */
