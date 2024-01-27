#include "include.h"

size_t	var_name_len(char *start)
{
	int		_;

	_ = 0;
	while (is_var(start[_]))
		_++;
	return (_);
}

size_t	*len_dollar(t_main *data, char *var)
{
	size_t * const	db = malloc(sizeof(size_t [2])); 

	db[1] = var_name_len(var);
	db[0] = ft_strlen(get_var_ref(data, var, db[1]));
	return (db); 
}

size_t	len_string(t_main *data, size_t offset)
{
	size_t	len;
	size_t	_;

	len = 0;
	_ = offset;
	while (data->line[_] != '\'' && data->line[_])
		(void)(len++, _++);
	return (len);
}

size_t	len_word(t_main *data, size_t offset)
{
	size_t	len;
	size_t	_;

	len = 0;
	_ = offset;
	while (is_word(data->line[_]) && !((data->line[_] == '$') && is_var(data->line[_ + 1])))
	{
		_++;
		len++;
	}
	return (len);
}

void		set_merge_flag(t_join *st, int val)
{
	if (val)
		st->merge_flag = 0;
	else
		st->merge_flag = 1;
}