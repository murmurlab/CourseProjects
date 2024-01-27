#include "include.h"

int		is_valid_identifier(char *id)
{
	size_t		_;

	_ = 0;
	while (((id[_] >= 'a') && (id[_] <= 'z')) || \
			((id[_] >= 'A') && (id[_] <= 'Z')) || (id[_] == '_'))
		_++;
	return (id[_]);
}

int		is_valid_value(char *id)
{
	size_t		_;

	_ = 0;
	while (((id[_] >= 'a') && (id[_] <= 'z')) || \
			((id[_] >= 'A') && (id[_] <= 'Z')) || \
			((id[_] >= '0') && (id[_] <= '9')) || \
			(id[_] == '_') || (id[_]))
		_++;
	return (id[_]);
}

int	is_var(int c)
{
	return (((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')) || (c >= '0' && c <= '9')
			|| (c == '?') || (c == '_')); // soru işareti sadece başta olacak
}

/**
 * @brief	('$' != c) && ('<' != c) &&
 * 			('>' != c) && ('\\\\'' != c) &&
 *			('"' != c) && ('|' != c) && (' ' != c)
 * @param c 
 * @return int 
 */
int	is_word(int c)
{
	return (('<' != c) && ('>' != c) && ('\'' != c) && ('"' != c) && \
			('|' != c) && (' ' != c) && ('\t' != c) && ('\0' != c) && \
			('\v' != c) && ('\f' != c) && ('\r' != c));
}

int	is_text(int c)
{
	return (('<' != c) && ('>' != c) && ('|' != c) && (' ' != c) && \
			('\t' != c) && ('\0' != c) && ('\v' != c) && ('\f' != c) && \
			('\r' != c));
}
