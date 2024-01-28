/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:15:20 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/28 20:34:24 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

/**
 * data.setval[0] = set_cmd;
 * data.setval[1] = set_arg;
 * data.setval[2] = set_in;
 * data.setval[3] = set_out;
*/
int	check_operation(t_main *data, int *oflags)
{
	if (data->line[data->_] == '<' && data->line[data->_ + 1] != '<')
		return (data->_++, *oflags |= O_RDONLY, 2);
	else if (data->line[data->_] == '>' && data->line[data->_ + 1] != '>')
		return (data->_++, *oflags |= O_TRUNC | O_WRONLY | O_CREAT, 3);
	else if (data->line[data->_] == '<' && data->line[data->_ + 1] == '<')
		return (data->_ += 2, 4);
	else if (data->line[data->_] == '>' && data->line[data->_ + 1] == '>')
		return (data->_ += 2, *oflags |= O_APPEND | O_WRONLY | O_CREAT, 3);
	else if ('|' == data->line[data->_])
		return (data->has_cmd = 0, data->_++, data->current++, 0);
	else if ('\0' != data->line[data->_])
		return (data->has_cmd);
	return (7);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	prompt_heredoc(char *label, int pipe[2])
{
	char		*buff;

	buff = NULL;
	buff = readline("> ");
	while (buff && ft_strcmp(label, buff))
	{
		write(pipe[1], buff, ft_strlen(buff));
		write(pipe[1], "\n", 1);
		free(buff);
		buff = readline("> ");
	}
	free(buff);
	write(pipe[1], "", 1);
	close(pipe[1]);
	return (0);
}

int	apply_list(t_list *list, t_turn2 *res, t_main *shell, int *oflags)
{
	while (list)
	{
		if ((shell->set_val[shell->to_be])(shell, list->content, *oflags) > \
			0)
			return (ft_lstclear(&res->nodes, no_del), 1);
		list = list->next;
	}
	return (0);
}

int	set_all(t_main *shell)
{
	t_list		*list;
	t_turn2		res;
	int			oflags;

	while ('0')
	{
		oflags = O_CLOEXEC;
		while (i_space(shell->line[shell->_]))
			shell->_++;
		shell->to_be = check_operation(shell, &oflags);
		while (i_space(shell->line[shell->_]))
			shell->_++;
		if (shell->to_be == 7)
			break ;
		res = expander(shell, shell->_);
		list = (res).nodes;
		if (apply_list(list, &res, shell, &oflags))
			return (1);
		ft_lstclear(&res.nodes, no_del);
		shell->_ += res.index - shell->_;
	}
	return (0);
}
