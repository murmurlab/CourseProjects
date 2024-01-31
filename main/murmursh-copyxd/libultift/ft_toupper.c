/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

int	ft_toupper(int c)
{
	if ((unsigned char)c > 96 && (unsigned char)c < 123)
		return (c - 32);
	return (c);
}
