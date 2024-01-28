/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:39:55 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/28 18:48:18 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*get(t_main *data, char const *var)
{
	t_list	*find;

	find = lst_filter(data->vars, check, (char *)var);
	if (find)
		return (strdup(ft_strchr(find->content, '=') + 1));
	return (NULL);
}

int	set(t_main *shell, char *duplex)
{
	t_list	*find;
	char	*discriminant;

	if (!duplex)
		return (1);
	discriminant = ft_strchr(duplex, '=');
	*(discriminant) = '\0';
	find = lst_filter(shell->vars, check, (char *)duplex);
	*discriminant = '=';
	if (!find)
		ft_lstadd_back(&shell->vars, ft_lstnew((char *)duplex));
	else
	{
		free(find->content);
		find->content = (char *)duplex;
	}
	return (0);
}

char	*get_ref(t_main *data, char const *var)
{
	t_list	*find;

	find = lst_filter(data->vars, check, (char *)var);
	if (find)
		return (ft_strchr(find->content, '=') + 1);
	return (NULL);
}

char	*get_var_ref(t_main *data, char *var_name, size_t len)
{
	const char	*name = ft_substr(var_name, 0, len);
	char		*var;

	if (name && name[0])
	{
		var = get_ref(data, name);
		return (free((void *)name), var);
	}
	else if (name)
		return (free((void *)name), NULL);
	return (NULL);
}

int	cpy_var(t_main *data, t_exp *exp, size_t offset)
{
	char		*var;
	const char	*name = ft_substr(data->line + offset, 0,
			exp->size = var_name_len(data->line + offset));

	if (name && name[0])
	{
		var = get_ref(data, name);
		if (var)
			while (*var)
				exp->ret[exp->duo[1]++] = *var++;
		return (free((void *)name), 0);
	}
	else if (name)
	{
		exp->ret[exp->duo[1]++] = data->line[offset - 1];
		return (free((void *)name), 0);
	}
	return (0);
}
