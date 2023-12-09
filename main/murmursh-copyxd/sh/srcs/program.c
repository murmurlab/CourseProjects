/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/12/07 19:25:08 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <stdarg.h>

int		qsignal;

int		set(t_main *data, char const * name, char const * value)
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

int	expander_str(t_main *data)
{

	while (data->line[data->_] != '\'')
	{
		
	}
	data->flags[0] = 0;
	return (0);
}

int	expander_var(t_main *data)
{
	char	*ret;

	
	while (data->line[data->_] != ' ')
	{
		
	}
	data->flags[0] = 0;
	return (0);
}

int	ft_var(int c)
{
	return (((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')) || (c >= '0' && c <= '9')
			|| (c == '?') || (c == '_'));
}

size_t	var_name_len(char *start)
{
	int		_;

	_ = 0;
	while (ft_var(start[_]))
		_++;
	if (_ > 0)
		return (_);
	return (0);
}

size_t	len_literal(t_main *data)
{
	size_t	len;
	size_t	_;
	size_t	size;

	_ = data->_;
	len = 0;
	while (data->line[_] != '"')
	{
		if (data->line[_] == '$')
		{
			_++;
			size = var_name_len(data->line + _);
			ft_substr(data->line + _, 0, size);
			len += ft_strlen(get_ref(data, ));
		}
		else
		{
			len++;
		}
		_++;
		// printf("ch: %c\n", data->line[data->_]);
	}
	return (len);
}

char	*expander_exp(t_main *data)
{
	size_t	i;
	char	*ret;
	size_t	stock;
	char	*tmp;
	
	i = 0;
	// printf("char ile girildi: %c\n", data->line[data->_]);
	data->_++;
	ret = malloc(sizeof(char) * len_literal(data));
	while (data->line[data->_] != '"')
	{
		if (data->line[data->_] == '$')
		{
			tmp = get_ref(data, var_name_len(data));
			while (*tmp)
				ret[i++] = *tmp++;
		}
		else
			ret[i++] = data->line[data->_];
		data->_++;
	}
	printf("result: %s\n", ret);
	data->flags[0] = 0;
	return (0);
}

int	parser(t_main *data)
{
	while (data->line[data->_] != 0)
	{
		if (data->line[data->_] == '"' && !data->flags[0])
			expander_exp(data);
		while (data->line[data->_] == '|')
		{
			// if ()
		}		
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
	printf("\n1\n");
	set(&data, strdup("PATH"), get(&data, "PATH"));
	printf("\n2\n");
	// printf("a: %s\n", (((char **)data.vars->content)[1]));
	// printf("a: %s\n", get(&data, "array"));

	ft_lstiter(data.vars, (void (*)(void *))f);
	
	// ioctl(STDIN_FILENO, TIOCSTI, "minishell$ ``");
	// write(1, "\033[A", 3);
	ft_memset(data.flags, 0, INT8_MAX);
	// tekte tanimla
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
