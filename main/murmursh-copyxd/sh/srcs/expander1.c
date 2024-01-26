#include "include.h"

void	dedect_text_type(t_main *shell, t_all *exp, t_turn *turn, char **ptr)
{
	if (shell->line[turn->index] == '\'')
	{
		exp->quote = shell->increases[((int)shell->line[turn->index])];
		exp->len = len_string(shell, turn->index + 1) + 2;
		ft_memcpy(*ptr, (shell->line + turn->index + 1), exp->len - 2);
	}
	else if (shell->line[turn->index] == '"') // else
	{
		exp->ptr = expander_exp(shell, *ptr, turn->index);
		*ptr += exp->ptr[1];
		turn->index += exp->ptr[0];
		free(exp->ptr);
	}
	else if (is_word(shell->line[turn->index]) && !((shell->line[turn->index] == '$') && is_var(shell->line[turn->index + 1]))) // else
	{
		exp->len = len_word(shell, turn->index);
		ft_memcpy(*ptr, (shell->line + turn->index), exp->len);
	}
}

size_t	len_all(t_main *data, size_t offset)
{
	t_all	exp;
	size_t	total;

	exp.len = (total = 0);
	exp.quote = 0;
	exp.index = offset;
	exp.ptr = malloc(sizeof(size_t [2]));
	ft_bzero(exp.ptr, sizeof(size_t [2]));
	while (is_text(data->line[exp.index]) && !((data->line[exp.index] == '$') \
										&& is_var(data->line[exp.index + 1])))
	{
		exp.quote = data->increases[((int)data->line[exp.index])];
		if (data->line[exp.index] == '\'')
			exp.len = len_string(data, exp.index + 1);
		else if (data->line[exp.index] == '"' && (free(exp.ptr), 1))
			exp.ptr = len_literal(data, exp.index + 1);
		else if (is_word(data->line[exp.index]) && !((data->line[exp.index] == \
									'$') && is_var(data->line[exp.index + 1])))
			exp.len = len_word(data, exp.index);
		exp.index += exp.len + (size_t)exp.quote + exp.ptr[1];
		total += exp.len + exp.ptr[0];
		exp.len = 0;
		ft_bzero(exp.ptr, sizeof(size_t [2]));
	}
	return (free(exp.ptr), total);
}

t_turn	join_all(t_main *shell, size_t offset)
{
	t_all			exp;
	t_turn			turn;
	char			*ptr;

	turn.buffer = calloc((len_all(shell, offset) * sizeof(char)) + sizeof(char), 1);
	if (!turn.buffer)
		return (turn.index = offset, turn);
	ptr = turn.buffer;
	turn.index = offset;
	exp.len = 0;
	exp.quote = 0;
	while (is_text(shell->line[turn.index]) && !((shell->line[turn.index] == '$') && \
			is_var(shell->line[turn.index + 1])))
	{
		dedect_text_type(shell, &exp, &turn, &ptr);
		turn.index += exp.len;
		ptr += exp.len - exp.quote;
		exp.quote = 0;
		exp.len = 0;
	}
	return (turn);
}
size_t	*len_literal(t_main *data, size_t offset)
{
	t_exp	exp;

	exp.duo = malloc(sizeof(size_t [2]));
	exp.duo[1] = offset;
	exp.duo[0] = 0;
	while (data->line[exp.duo[1]] != '"' && data->line[exp.duo[1]])
	{
		if (data->line[exp.duo[1]] == '$')
		{
			exp.duo[1]++;
			exp.var_value = get_var_ref(data, data->line + exp.duo[1], exp.size = \
										var_name_len(data->line + exp.duo[1]));
			if (exp.size)
			{
				if (exp.var_value)
					exp.duo[0] += ft_strlen(exp.var_value);
				exp.duo[1] += exp.size;
			}
			else
				exp.duo[0]++;
		}
		else
			(void)(exp.duo[0]++, exp.duo[1]++);
	}
	return (exp.duo[1] -= offset, exp.duo);
}

size_t	*expander_exp(t_main *data, char *dst, size_t offset)
{
	t_exp	exp;

	offset++;
	exp.duo = malloc(sizeof(size_t [2]));
	exp.duo[0] = 0;
	exp.duo[1] = 0;
	// printf("len: %i data_: %zu\n", len_literal(data, _)[0], _);
	exp.ret = dst;
	while (data->line[offset + exp.duo[0]] != '"' && data->line[offset + exp.duo[0]])
	{
		if (data->line[offset + exp.duo[0]] == '$')
		{
			if (cpy_var(data, &exp, offset + exp.duo[0] + 1))
				return (NULL);
			exp.duo[0] += exp.size + 1;
		}
		else
			exp.ret[exp.duo[1]++] = data->line[offset + exp.duo[0]++];
	}
	exp.duo[0] += 2;
	// printf("0: [%zu] 1: %zu\n", exp.duo[0], exp.duo[1]);
	return (exp.duo);
}
