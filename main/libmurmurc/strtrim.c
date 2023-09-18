





// ahbasara

#include "murmurlibc.h"

char	*strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && xstrchr(set, *s1))
		s1++;
	i = xstrlen(s1);
	while (i && xstrchr(set, s1[i]))
		i--;
	return (strcut(s1, 0, i + 1));
}

/* int	main(void)
{
	char	*str = "   xxx/xtestttxxx ";
	char	*set = "x ";

	printf("%s", ft_strtrim(str, set));
} */
