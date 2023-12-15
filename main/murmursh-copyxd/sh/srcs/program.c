/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/12/15 03:12:35 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "testing.h"
#include <stdarg.h>

int		qsignal;

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
	size_t	len;
	t_exp	exp;
	size_t	*ret;

	exp.i = offset;
	len = 0;
	ret = malloc(sizeof(size_t) * 2);
	while (data->line[exp.i] != '"' && data->line[exp.i])
	{
		if (data->line[exp.i] == '$')
		{
			exp.i++;
			exp.size = var_name_len(data->line + exp.i);
			exp.var_name = ft_substr(data->line + exp.i, 0, exp.size);
			if (exp.var_name && exp.var_name[0])
			{
				exp.var_value = get_ref(data, exp.var_name);
				if (exp.var_value)
					len += ft_strlen(exp.var_value);
				exp.i += exp.size;
			}
			else
				len++;
			free(exp.var_name);
		}
		else
			(void)(len++, exp.i++);
	}
	printf("len literal: %zu sizereal: %zu\n", len, exp.i - offset);
	ret[0] = len;
	ret[1] = exp.i - offset;
	return (ret);
}

size_t	len_string(t_main *data, size_t offset)
{
	size_t	len;
	size_t	_;

	len = 0;
	_ = offset;
	while (data->line[_] != '\'' && data->line[_])
		(void)(len++, _++);
	printf("len string: %zu\n", len);
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
	printf("len normal: %zu\n", len);
	return (len);
}

size_t	len_all(t_main *data, size_t offset)
{
	size_t	total;
	size_t	len;
	int		quote;
	size_t	index;
	size_t	*bakcup;
	// size_t	left;

	// left = var_name_len(data->line);
	len = 0;
	total = 0;
	quote = 0;
	index = offset;
	bakcup = malloc(sizeof(size_t) * 2);
	bakcup[0] = 0;
	bakcup[1] = 0;
	while (is_text(data->line[index]) && !((data->line[index] == '$') && is_var(data->line[index + 1])))
	{
		quote = data->increases[data->line[index]];
		if (data->line[index] == '\'')
			len = len_string(data, index + (quote / 2));
		if (data->line[index] == '"') // else
		{
			free(bakcup);
			bakcup = len_literal(data, index + (quote / 2));
		}
		if (is_word(data->line[index]) && !((data->line[index] == '$') && is_var(data->line[index + 1]))) // else
			len = len_word(data, index + (quote / 2));
		index += len + (size_t)quote + bakcup[1];
		total += len + bakcup[0];
		len = 0;
		bakcup[0] = 0;
		bakcup[1] = 0;
	}
	free(bakcup);
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
	exp->var_value = get_var_ref(data, (data->line + _), \
								exp->size = var_name_len(data->line + _));
	if (exp->var_value)
		while (*exp->var_value)
			exp->ret[exp->i++] = *exp->var_value++;
	_ += exp->size;
	if (!exp->var_value)
		exp->ret[exp->i++] = data->line[_ - 1]; // "$"
	return (0);
}

char	*expander_exp(t_main *data, size_t offset)
{
	t_exp	exp;
	size_t	_;

	exp.i = 0;
	_ = offset + 1;
	printf("len: %zu data_: %zu\n", len_literal(data, _)[0], _);
	exp.ret = calloc(sizeof(char), len_literal(data, _)[0] + 1);
	if (!exp.ret)
		return (NULL);
	while (data->line[_] != '"' && data->line[_])
	{
		if (data->line[_] == '$')
		{
			if (cpy_var(data, &exp, _ + 1))
				return (NULL);
			_ += exp.size + 1;
		}
		else
			exp.ret[exp.i++] = data->line[_++];
	}
	printf("result: [%s] i: %zu\n", exp.ret, exp.i);
	return (exp.ret);
	// 
}

// char	*expander_exp2(t_main *data)
// {
// 	t_exp	exp;

// 	exp.i = 0;
// 	exp.size = 1;
// 	data->_++;
// 	printf("len: %zu data_: %d\n", len_literal(data, data->_)[0], data->_);
// 	exp.ret = calloc(sizeof(char), len_literal(data, data->_)[0] + 1);
// 	if (!exp.ret)
// 		return (NULL);
// 	while (data->line[data->_] != '"' && data->line[data->_])
// 	{
// 		if (data->line[data->_] == '$')
// 		{
// 			if (cpy_var(data, &exp))
// 				return (NULL);
// 		}
// 		else
// 			exp.ret[exp.i++] = data->line[data->_++];
// 	}
// 	printf("log11111111111111111111111111111111\n");
// 	printf("result: %s i: %zu\n", exp.ret, exp.i);
// 	return (exp.ret);
// }

char	*join_all(t_main *data, size_t offset)
{
	const size_t	end_len = len_all(data, 0);
	char const		*end_string = malloc(end_len * sizeof(char));
	size_t			_str;
	size_t			_new;

	
	_str = offset;
	while (is_text(data->line[_str]))
	{
		return (9);
	}
	
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
		// 1$a'$a'""1""$a''$a $a
		// 123123'123'1"12"1
		// 123123'123'1"12"1
		// "a$a99-$a"
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