/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= 'a' && c <= 'z'))
		return (2);
	return (0);
}
