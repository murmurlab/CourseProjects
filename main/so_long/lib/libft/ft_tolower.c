/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

int	ft_tolower(int c)
{
	if ((unsigned char)c > 64 && (unsigned char)c < 91)
		return (c + 32);
	return (c);
}
