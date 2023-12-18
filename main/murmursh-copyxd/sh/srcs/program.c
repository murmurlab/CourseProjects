/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/12/18 17:08:08 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "testing.h"
#include <stdarg.h>

int		qsignal;

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int		set(t_main *data, char const *name, char const *value)
{
	char const	**a;
	t_list	*find;

	find = lst_filter(data->vars, check, name);
	if (!find)
	{
		a = malloc(2 * sizeof(char *));
		a[0] = name;
		a[1] = value;
		ft_lstadd_back(&data->vars, ft_lstnew(a));
	}
	else
	{
		free((char *)name);
		free(((char **)find->content)[1]);
		((char const **)find->content)[1] = value;
	}
	return (0);
}

int	check(t_list *node, void *cmp)
{
	if (!strcmp(((char **)(node->content))[0], (char const *)cmp))
		return (1);
	return (0);
}

char	*get(t_main *data, char const *var)
{
	t_list	*find;

	find = lst_filter(data->vars, check, var);
	if (find)
		return (strdup(((char **)find->content)[1]));
	return (strdup(getenv(var)));
}

char	*get_ref(t_main *data, char const *var)
{
	t_list	*find;

	find = lst_filter(data->vars, check, var);
	if (find)
		return (((char **)find->content)[1]);
	return (getenv(var));
}

void	coix(int sig)
{
	// sleep(1);
	// printf("%c%c", 8, 8);
	rl_on_new_line();
	// rl_replace_line("", 1);
	printf("\033[K");
	rl_redisplay();
	qsignal = 1;
}

covid	ctrl_c(int sig)
{
	rl_replace_line("", 0);
	rl_on_new_line();
	printf("\n");
	rl_redisplay();
}

int	sh_exit(t_com *coms)
{
	// rl_on_new_line();
	// rl_replace_line("goodbye👋\n", 12);
	// \033[A\033[;9H 
	printf("exit\n");
	// rl_redisplay();
	exit(0);
}

int	sh_cd(t_com *coms, char *dir)
{
	return (0);
}

int	exe(t_com *coms, char *cmd)
{
	int		_;

	_ = 0;
	while (_ < CMD_COUNT)
	{
		if (!strcmp(cmd, coms[_].name))
		{
			(free(cmd), coms[_].func(coms));
			return (0);
		}
		_++;
	}
	if (cmd && cmd[0] != '\0')
		printf("%s %s", cmd, ": command not found\n");
	// printf("\n");
	free(cmd);
	return (0);
}
// size_t	get_len(t_var *var)
// {
// 	strlen
// }

int	is_var(int c)
{
	return (((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')) || (c >= '0' && c <= '9')
			|| (c == '?') || (c == '_'));
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
	return (('<' != c) && ('>' != c) && ('\'' != c) && \
			('"' != c) && ('|' != c) && (' ' != c) && ('\0' != c));
}

int	is_text(int c)
{
	return (('<' != c) && ('>' != c) && \
			('|' != c) && (' ' != c) && ('\0' != c));
}

size_t	var_name_len(char *start)
{
	int		_;

	_ = 0;
	while (is_var(start[_]))
		_++;
	return (_);
}

size_t	*len_literal(t_main *data, size_t offset)
{
	t_exp	exp;

	exp.duo = malloc(sizeof(size_t) * 2);
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
	// printf("len literal: %zu sizereal: %zu\n", exp.duo[0], exp.duo[1] - offset);
	exp.duo[1] -= offset;
	return (exp.duo);
}

size_t	len_string(t_main *data, size_t offset)
{
	size_t	len;
	size_t	_;

	len = 0;
	_ = offset;
	while (data->line[_] != '\'' && data->line[_])
		(void)(len++, _++);
	// printf("len string: %zu\n", len);
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
	// printf("len normal: %zu\n", len);
	return (len);
}

size_t	len_all(t_main *data, size_t offset)
{
	t_all	exp;
	size_t	total;

	exp.len = 0;
	total = 0;
	exp.quote = 0;
	exp.index = offset;
	exp.ptr = malloc(sizeof(size_t) * 2);
	ft_bzero(exp.ptr, sizeof(size_t) * 2);
	while (is_text(data->line[exp.index]) && !((data->line[exp.index] == '$') \
										&& is_var(data->line[exp.index + 1])))
	{
		exp.quote = data->increases[data->line[exp.index]];
		if (data->line[exp.index] == '\'')
			exp.len = len_string(data, exp.index + (exp.quote / 2));
		else if (data->line[exp.index] == '"' && (free(exp.ptr), 1))
			exp.ptr = len_literal(data, exp.index + (exp.quote / 2));
		else if (is_word(data->line[exp.index]) && !((data->line[exp.index] == \
									'$') && is_var(data->line[exp.index + 1])))
			exp.len = len_word(data, exp.index + (exp.quote / 2));
		exp.index += exp.len + (size_t)exp.quote + exp.ptr[1];
		total += exp.len + exp.ptr[0];
		exp.len = 0;
		ft_bzero(exp.ptr, sizeof(size_t) * 2);
	}
	free(exp.ptr);
	printf("len: %zu\n", total);
	return (total);
}

/**
 * @brief get_var(data, after_dollar, var_name_len(after_dollar))
 * 
 * @param data 
 * @param after_dollar 
 * @param len 
 * @return char* 
 */
char	*get_var_ref(t_main *data, char *var_name, size_t len)
{
	const char	*name = ft_substr(var_name, 0, len);
	char		*tmp;

	if (name && name[0])
	{
		tmp = get_ref(data, name);
		return (free((void *)name), tmp);
	}
	else if (name)
		return (free((void *)name), NULL);
	return (NULL);
}

int		cpy_var(t_main *data, t_exp *exp, size_t offset)
{
	size_t _;
	_ = offset;
	char		*tmp;
	const char	*name = ft_substr(data->line + _, 0, exp->size = var_name_len(data->line + _));

	if (name && name[0])
	{
		tmp = get_ref(data, name);
		if (tmp)
			while (*tmp)
				exp->ret[exp->duo[1]++] = *tmp++;
		_ += exp->size;
		return (free((void *)name), 0);
	}
	else if (name)
	{
		exp->ret[exp->duo[1]++] = data->line[_ - 1]; // "$"
		return (free((void *)name), 0);
	}
	return (0);
}

size_t	*expander_exp(t_main *data, char *dst, size_t offset)
{
	t_exp	exp;

	exp.duo = malloc(sizeof(size_t) * 2);
	exp.duo[0] = offset + 1;
	exp.duo[1] = 0;
	// printf("len: %i data_: %zu\n", len_literal(data, _)[0], _);
	exp.ret = dst;
	while (data->line[exp.duo[0]] != '"' && data->line[exp.duo[0]])
	{
		if (data->line[exp.duo[0]] == '$')
		{
			if (cpy_var(data, &exp, exp.duo[0] + 1))
				return (NULL);
			exp.duo[0] += exp.size + 1;
		}
		else
			exp.ret[exp.duo[1]++] = data->line[exp.duo[0]++];
	}
	// printf("result: [%zu] i: %zu\n", exp.duo[0], exp.duo[1]);
	return (exp.duo);
}

char	*join_all(t_main *data, size_t offset)
{
	const size_t	all_len = len_all(data, 0);
	char const		*buffer = malloc((all_len * sizeof(char)) + sizeof(char));
	t_all			exp;
	
	exp.buff_index = 0;
	exp.index = offset;
	exp.len = 0;
	exp.quote = 0;
	((char *)buffer)[all_len] = 0;
	// exp.ptr = malloc(sizeof(size_t) * 2);
	// ft_bzero(exp.ptr, sizeof(size_t) * 2);
	while (is_text(data->line[exp.index]) && !((data->line[exp.index] == '$') && \
			is_var(data->line[exp.index + 1])))
	{
		exp.quote = data->increases[data->line[exp.index]];
		if (data->line[exp.index] == '\'')
		{
			exp.len = len_string(data, exp.index + 1);
			ft_memcpy((char *)buffer + exp.buff_index, (data->line + exp.index + 1), exp.len);
		}
		else if (data->line[exp.index] == '"') // else
		{
			exp.ptr = expander_exp(data, (char *)buffer + exp.buff_index, exp.index);
			exp.buff_index += exp.ptr[1];
			exp.index += exp.ptr[0];
			free(exp.ptr);
			// exp.index++;
		}
		else if (is_word(data->line[exp.index]) && !((data->line[exp.index] == '$') && is_var(data->line[exp.index + 1]))) // else
		{
			exp.len = len_word(data, exp.index + 1);
			ft_memcpy((char *)buffer + exp.buff_index, (data->line + exp.index), exp.len);
		}
		exp.index += exp.len + (size_t)exp.quote;
		exp.buff_index += exp.len;
		// total += len + bakcup[0];
		exp.len = 0;
		// return (NULL);
	}
	printf("%s: %s\n", __func__, (char *)buffer);
	return ((char *)buffer);
}

// int	set_value(t_main *data, char *str)
// {
// 		if (!data->flags[5])
// 			{
// 				// data->cmds = ;
// 			}
// }


int	parser(t_main *data)
{
	static char	*a;

	while (data->line[data->_] != 0)
	{
		// if (data->line[data->_] == '"')
		// {
		// 	printf("1: [%c]\n", data->line[data->_]);
		// 	expander_exp(data);
		// 	printf("2: [%c]\n", data->line[data->_]);
		// }
		// else if (data->line[data->_] == '\'')
		// {
		// 	data->_++;
		// 	printf("1.5: %zu\n", len_string(data, 1));
		// 	exit(0);
		// }
		// else if (is_word(data->line[data->_]))
		// {
		// 	printf("1.5: %zu\n", len(data, 0));
		// 	exit(0);
		// }
		// expander_exp(data, data->_);
		// expander_exp2(data);
		if (TEST)
			run_test();
		join_all(data, data->_);
		break ;
		data->_++;
	}
	
	return (0);
}

void	f(t_list *node)
{
	printf("var %s: %s\n", ((char **)(node))[0], ((char **)node)[1]);
}

void	f2(t_list *node)
{
	free(((char **)(node))[0]);
	free(((char **)(node))[1]);
	free(node);
}

int	main(void)
{
	int			fd;
	int			p[2][2];
	pid_t		pid;
	char		**args;
	t_main		data;

	// printf("%s\n", getenv("PATH"));
	data.vars = NULL;

	char *cy;
	set(&data, strdup("nnnnn"), strdup("313131"));
	set(&data, strdup("array"), strdup("value"));
	set(&data, strdup("nnnnn"), strdup("tttt"));
	set(&data, strdup("nnnnn"), strdup("cccc"));
	set(&data, strdup("nnnnn"), strdup("rrrrr"));
	set(&data, strdup("a"), strdup("0000"));
	printf("ENV: %s\n", cy = get(&data, "PATH"));
	free(cy);
	set(&data, strdup("PATH"), get(&data, "PATH"));
	set(&data, strdup("PATH"), get(&data, "PATH"));
	// printf("a: %s\n", (((char **)data.vars->content)[1]));
	// printf("a: %s\n", get(&data, "array"));

	ft_lstiter(data.vars, (void (*)(void *))f);
	
	// ioctl(STDIN_FILENO, TIOCSTI, "minishell$ ``");
	// write(1, "\033[A", 3);
	ft_memset(data.flags, 0, INT8_MAX);
	// tekte tanimla
	// data.fun = malloc(sizeof(size_t (*)(t_main *data, size_t offset)) * 3);
	ft_bzero(data.increases, INT8_MAX);
	data.increases['"'] = (char)2;
	data.increases['\''] = (char)2;
	data.increases[0] = (char)0;
	data.cmds = NULL;
	data.coms = (t_com []){
		(t_com){"echo", 0, 1},
		(t_com){"cd", 0, 1},
		(t_com){"pwd", 0, 1},
		(t_com){"export", 0, 1},
		(t_com){"unset", 0, 1},
		(t_com){"env", 0, 1},
		(t_com){"exit", sh_exit, 1},
		(t_com){"x", sh_exit, 1}
	};
	chdir("/");
	// printf("prog started %s\n", getcwd(NULL, 0));
	// data.coid = 1;
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, coix);
	// args = malloc(3 * sizeof(char *));
	// args[0] = strdup("/bin/ls");
	// args[1] = strdup("-la");
	// args[2] = 0;
			// getchar();
	fd = open("program.c", O_RDONLY);
	pipe(p[0]);
	pipe(p[1]);
	// read(0, data.line, 99999);
	// printf("00000000000\n");
	//printf("%s", GREEN PROMT RESET);

	// data.line = readline(GREEN PROMT RESET);
	// parser(&data);
	// if (data.line)
	// 	exe(data.coms, data.line);
	// else
	// {
	// 	free(data.line);
	// 	if (1)
	// 	{
	// 		printf("\033[A");
	// 		printf(GREEN PROMT RESET);
	// 		sh_exit(&data.coms[6]);
	// 	}
	// 	qsignal = 0;
	// 	printf("\n");
	// }
	while (1)
	{
		// printf("%s", );
		// rl_erase_empty_line = 1;

		// rl_already_prompted = 1;
		data.line = readline(GREEN PROMT RESET);
		if (data.line)
		{
			if (data.line[0] != 0)
			{
				data._ = 0;
				parser(&data);
				// exe(data.coms, data.line);
			}
			free(data.line);
		}
		else
		{
			free(data.line);
			if (1)
			{
				printf("\033[A");
				printf(GREEN PROMT RESET);
				fflush(stdout);
				sh_exit(&data.coms[6]);
			}
			qsignal = 0;
			printf("\n");
		}
		// rl_on_new_line();
		// free(data.line);
	}
	ft_lstiter(data.vars, (void (*)(void *))f2);
	t_list *tmp;
	while (data.vars)
	{
		tmp = data.vars->next;
		free(data.vars);
		data.vars = tmp;
	}
	
	// if (fork())
	// {

	// }
	// else
	// {
		
	// }
}

/**2.
 *  in pipe 
 * out ft_değisken
*/
// <file grep | cat >"ft_$out"
/**
 * void	__attribute__((destructor))after_main()
 * {
 * 	pause();
 * }
 */

// 🙂
// int smile()
// {
// 	return(1);
// }
// 🤔
// int think()
// {
// 	while (1)
// 	{}
// }
// 😡
// int angry()
// {
// 	return(-1);
// }
// 😴
// void sleep()
// {
// 	pause();
// }
// 😐
// char indecisive()
// {
// 	return (0);
// }