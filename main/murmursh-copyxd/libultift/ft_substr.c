/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#include <sys/_types/_null.h>
#include <sys/_types/_size_t.h>

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i_j_l[3];
	char	*str;

	if (!s)
		return (NULL);
	i_j_l[2] = ft_strlen(s);
	if (start >= i_j_l[2] || !len)
		return (ft_strdup(""));
	if (i_j_l[2] - start > len)
		str = ft_calloc(sizeof(*s), (len + 1));
	else
		str = ft_calloc(sizeof(*s), (i_j_l[2] - start + 1));
	if (!str)
		return (NULL);
	i_j_l[0] = -1;
	i_j_l[1] = 0;
	while (s[++i_j_l[0]])
		if (i_j_l[0] >= start && i_j_l[1] < len)
			str[i_j_l[1]++] = s[i_j_l[0]];
	return (str);
}
