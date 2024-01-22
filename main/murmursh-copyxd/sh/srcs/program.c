/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/22 15:15:21 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <stdarg.h>

int		g_qsignal;

// char	*mod_strcpy(char *dest, char *src)
// {
// 	unsigned int i;

// 	i = 0;
// 	while (src[i] != '\0')
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = src[i];
// 	return (dest + i);
// }

// void	*mod_memcpy(void *dest, const void *src, size_t n)
// {
// 	char	*d;
// 	char	*s;

// 	if (!src && !dest)
// 		return (dest);
// 	d = (char *)dest;
// 	s = (char *)src;
// 	while (n--)
// 		*d++ = *s++;
// 	return (d);
// }

char	*ft_strsjoin(t_merge *strs[])
{
	void		*ret;
	char		*s;
	size_t		_;

	_ = 0;
	s = 0;
	while (strs[_])
		s += strs[_++]->len;
	if (!s)
		return (NULL);
	s = (ret = ft_calloc(sizeof(char), (size_t)s + 1));
	if (s == NULL)
		return (NULL);
	_ = 0;
	while (strs[_])
	  {
		if (strs[_]->str)
			while (strs[_]->len--)
				*s++ = *(strs[_]->str)++;
		_++;
	}
	return (ret);
}

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

void	e(int err)
{
	write(2, "shell: ", 7);
	write(2, strerror(EACCES), ft_strlen(strerror(EACCES)));
	write(2, "\n", 1);
}

void	e2(char *s)
{
	write(2, s, ft_strlen(s));
}

/**
 * ast=0
 * ast0
 */
int		strccmp(const char *s1, const char *s2, char ch)
{
	size_t			i;
	unsigned char	*one;
	unsigned char	*two;
	char			diff;

	i = 0;
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (one[i] || two[i])
	{
		if (one[i] != two[i])
		{
			diff = (one[i] - two[i]);
			if (diff == ch || diff == -ch)
				return (i);
			return (0);
		}
		i++;
	}
	return (0);
}

int		set(t_main *shell, char *duplex)
{
	t_list	*find;
	char	*discriminant;

	*(discriminant = ft_strchr(duplex, '=')) = '\0';
	find = lst_filter(shell->vars, check, (char *)duplex);
	*discriminant = '=';
	if (!find)
	{
		ft_lstadd_back(&shell->vars, ft_lstnew((char *)duplex));
		return (0);
	}
	else
	{
		free(find->content);
		find->content = (char *)duplex;
	}
	return (1);
}

int	check(t_list *node, void *cmp)
{
	if (strccmp(node->content, cmp, '='))
		return (1);
	return (0);
}

// int	check2(t_list *node, void *cmp)
// {
// 	if (strccmp(node->content, cmp, '='))
// 		return (1);
// 	return (0);
// }

char	*get(t_main *data, char const *var)
{
	t_list	*find;

	find = lst_filter(data->vars, check, (char *)var);
	if (find)
		return (strdup(ft_strchr(find->content, '=') + 1));
	return (NULL);
}

char	*get_ref(t_main *data, char const *var)
{
	t_list	*find;

	find = lst_filter(data->vars, check, (char *)var);
	if (find)
		return (ft_strchr(find->content, '=') + 1);
	return (NULL);
}

void	coix(int sig)
{
	// sleep(1);
	// printf("%c%c", 8, 8);
	rl_on_new_line();
	// rl_replace_line("", 1);
	printf("\033[K");
	rl_redisplay();
	g_qsignal = 1;
}

covid	ctrl_c(int sig)
{
	if (!g_qsignal)
	{
		printf("\n");
		rl_replace_line("", 0); // set the current input to given string
		rl_on_new_line(); // set the current line to promt + input
		rl_redisplay(); // set the start of cursor to end		
	}
	else
		printf("\n");
	// printf(GREEN PROMT RESET);
}

int		sh_exit(t_main *shell, t_execd *execd)
{
	// rl_on_new_line();
	// rl_replace_line("goodbye👋\n", 12);
	// \033[A\033[;9H 
	printf("exit\n");
	// rl_redisplay();
	if (shell->cmds[execd->_].args->next)
		exit(ft_atoi(shell->cmds[execd->_].args->next->content));
	exit(shell->ex_stat);
}

int		sh_pwd(t_main *shell, t_execd *execd)
{
	if (getcwd(shell->cwd, MAX_CWD))
		printf("%s\n", shell->cwd);
	else
		return (perror("shell says: pwd: "), 1);
	return (0);
}

void	f3(t_list *node)
{
	printf("declare -x %s\n", (char *)node);
}

// Bash --posix: [a-zA-Z_][0-9a-zA-Z_]*

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

int		sh_export(t_main *shell, t_execd *execd)
{
	t_list		*arg;
	char		*tmp;
	int			err;
	int			gerr;
	char		*to_set;
	char		validate;
	
	err = 0;
	gerr = 0;
	arg = shell->cmds[execd->_].args->next;
	if (arg)
	{
		while (arg)
		{
			tmp = ft_strchr(arg->content, '=');
			if (tmp)
			{
				if (tmp == arg->content || is_valid_value(tmp + 1))
					gerr = (err = 1);
				*tmp = '\0';
			}
			validate = is_valid_identifier(arg->content);
			if (tmp)
			{
				*tmp = '=';
				to_set = arg->content;
			}
			else
				to_set = ft_strjoin(arg->content, "=");
			if (!err && !validate)
				set(shell, to_set);
			else
				printf("export: `%s': not a valid identifier\n", (char *)arg->content);
			arg = arg->next;
			err = 0x0;
		}
	}
	else
		ft_lstiter(shell->vars, (void (*)(void *))f3);
	return (gerr);
}

t_list	*lst_filter_prev(t_list *nod, int f(t_list *node_iterate, void *data_compare), void *data)
{
	t_list		*prev;
	
	prev = nod;
	while (nod)
	{
        if (f(nod, data))
            return (prev);
		prev = nod;
		nod = nod->next;
	}
	return (NULL);
}

void	del(void *_)
{
	free(_);
}

int		sh_unset(t_main *shell, t_execd *execd)
{
	// char	*discriminant;
	t_list	*find;
	t_list	*backup;
	t_list	*arg;
	int		gerr;
	// *(discriminant = ft_strchr(duplex, '=')) = '\0';
	// *discriminant = '=';
	arg = shell->cmds[execd->_].args->next;
	gerr = 0;
	while (arg)
	{
		find = lst_filter_prev(shell->vars, check, arg->content);
		if (is_valid_identifier(arg->content))
			gerr = (printf("export: `%s': not a valid identifier\n", (char *)arg->content), 1);
		if (!find)
		{
			arg = arg->next;
			continue ;
		}
		if (find == shell->vars)
		{
			shell->vars = find->next;
			ft_lstdelone(find, del);
		}
		else
		{
			backup = find->next;
			find->next = find->next->next;
			ft_lstdelone(backup, del);
		}
		arg = arg->next;
	}
	return (gerr);
}

int		sh_env(t_main *shell, t_execd *execd)
{
	ft_lstiter(shell->vars, (void (*)(void *))f);
	return (0);
}

int		sh_echo(t_main *shell, t_execd *execd)
{
	t_list const	*arg = shell->cmds[execd->_].args->next;
	int				n_flag = !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!0;

	if (arg)
	{
		if (((char *)arg->content)[0] == '-' && ((char *)arg->content)[1] == 'n')
		{
			arg = arg->next;
			n_flag = 1;
		}
		if (arg)
		{
			while (!0)
			{
				printf("%s", (char *)arg->content);
				arg = arg->next;
				if (!arg)
					break ;
				printf(" ");
			}
		}
	}
	// shell->cmds[execd->_].args->content
	if (((((((((((((((((((((((((((((((((!n_flag)))))))))))))))))))))))))))))))))
		printf("\n");
	return (0);
}

void	set_working_dirs(t_main *shell, char *pwd, char *oldpwd)
{
	set(shell, ft_strsjoin((t_merge *[]){&(t_merge){"OLDPWD", 6},
			&(t_merge){"=", 1}, &(t_merge){oldpwd,
			ft_strlen(oldpwd)}, NULL}));
	set(shell, ft_strsjoin((t_merge *[]){&(t_merge){"PWD", 3},
			&(t_merge){"=", 1}, &(t_merge){pwd,
			ft_strlen(pwd)}, NULL}));
}

void	update_pwd(t_main *shell, t_cd *cd)
{
	getcwd(shell->cwd, MAX_CWD);
	cd->workdirs[0] = ft_strdup(get_ref(shell, "PWD"));
	cd->workdirs[1] = ft_strdup(get_ref(shell, "OLDPWD"));
	if (cd->backflag)
		set_working_dirs(shell, cd->workdirs[1], cd->workdirs[0]);
	else
		set_working_dirs(shell, shell->cwd, cd->workdirs[0]);
	free(cd->workdirs[0]);
	free(cd->workdirs[1]);
}

	// t_com const * const		self = \
	// 		shell->coms + shell->cmds[execd->_].builtin_offset;

int		sh_cd(t_main *shell, t_execd *execd)
{
	t_cd					cd;

	cd.param = shell->cmds[execd->_].args->next;
	if (cd.param)
	{
		cd.backflag = !strcmp("-", cd.param->content);
		if (cd.backflag)
			cd.err = chdir(get_ref(shell, "OLDPWD"));
		else
			cd.err = chdir(cd.param->content);
		if (cd.err)
			perror("shell says: cd: ");
		else
			update_pwd(shell, &cd);
		return (cd.err);
	}
	else
	{
		cd.backflag = 0;
		cd.err = chdir(get_ref(shell, "HOME"));
		if (cd.err)
			perror("shell says: cd");
		else
			update_pwd(shell, &cd);
		return (cd.err);
	}
}

int	err(int e, char *str)
{
	errno = e;
	if (e == IS_A_DIR)
	{
		e2(str);
		e2(IS_A_DIR_MSG);
	}
	else if (e == ENOENT)
		perror(str);
	else if (e == EACCES)
		perror(str);
	else if (e == EPERM)
		perror(str);
	else
		perror(str);
	return (0);
}

char	*resolve_cmd(t_main *shell, char *string)
{
	char		*loc;
	char		*path;

	path = (get_ref(shell ,"PATH"));
	loc = check_cmd(string, path);
	if (!loc)
	{
		e2("command not found: ");
		e2(string);
		e2("\n");
	}
	shell->ex_stat = 127;
	return (loc);
}

void	search_builtins(t_main *shell, int cmd_off)
{
	int																	o__o;
	
	o__o = 01;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	while (o__o < 0x8)
	{
		if (!strcmp(shell->cmds[cmd_off].cmd, shell->coms[o__o].name))
		{
			shell->cmds[cmd_off].builtin_offset = o__o;;
			return ;
		}
		(++o__o);
	}
	shell->cmds[cmd_off].builtin_offset = 0b00000000000000000000000000000000;;
	return ;
}

void	set_path(t_main *shell)
{
	size_t		_;
	void		*var;
	struct stat sb;

	_ = -1;
	while (++_ < shell->cmd_ct)
	{
		if (!shell->cmds[_].args)
			continue ;
		// printf("> log111 %zu \n", _);
		// printf("> log222 %s \n", shell->cmds[_].cmd);
		if (!ft_strchr(shell->cmds[_].cmd, '/'))
		{
			search_builtins(shell, _);
			
			if (shell->cmds[_].builtin_offset)
				continue ;
			var = shell->cmds[_].cmd;
			errno = 0;
			shell->cmds[_].cmd = resolve_cmd(shell, shell->cmds[_].cmd);
			free(var);
		}
		else
		{
			stat(shell->cmds[_].cmd, &sb);
			if (errno)
				err(errno, shell->cmds[_].cmd);
			if (S_ISDIR(sb.st_mode))
				err(IS_A_DIR, shell->cmds[_].cmd);
			if (access(shell->cmds[_].cmd, X_OK))
			{
				free(shell->cmds[_].cmd);
				shell->cmds[_].cmd = NULL;
			}
		}
	}
}

/**
 * replace `if (path[_] == ':' || !path[_])` to `if (path[_] == ':')`
 * 
 * move the following lines to outside the while
 * if (!path[_])
 * 		break ;
 */
char	*check_cmd(char *cmd, char *path)
{
	char		*var;
	size_t		_;
	struct stat sb;

	if (!path)
		return (NULL);
	_ = 0;
	while ("")
	{
		if (path[_] == ':' || !path[_])
		{
			if (!path[_] && !_)
				break ;
			var = ft_strsjoin((t_merge *[]){ \
									&(t_merge){path, _},
									&(t_merge){"/", 1},
									&(t_merge){cmd, ft_strlen(cmd)}, NULL
								});
			// dprintf(2, "> %s\n", var);
			errno = 0;
			stat(var, &sb);
			if (!errno)
			{
				if (S_ISREG(sb.st_mode))
				{
					if (!access(var, X_OK))
						break ;
					else
						err(EPERM, cmd);
				}
			}
			free(var);
			var = NULL;
			if (!path[_])
				break ;
			path += _ + 1;
			_ = 0;
		}
		if (path[_])
			_++;
	}
	return (var);
}

void	close_pipes(t_main *data, t_execd *execd)
{
	size_t													_;

	_ = 1;
	if (execd->_ != 0) // not first
		close(execd->fd[0][1]);
	else if ((execd->_ != (data->cmd_ct - 1)) && (data->cmd_ct != 1)) // not last
		close(execd->fd[data->cmd_ct - 2][0]); // close last pipe read
	if (execd->_ == 0 && data->cmd_ct != 1 && data->cmd_ct != 2)
	{
		// dprintf(2, "ff closed end of read %lu. pipes, end of write %zu. pipes in %zu. process\n", _ - 1, _, execd->_);		
		close(execd->fd[_ - 1][0]);
		close(execd->fd[_][1]);
	}
	while (_ < execd->_)
	{
		// dprintf(2, "ss closed end of read %lu. pipes, end of write %zu. pipes in %zu. process\n", _ - 1, _, execd->_);
		close(execd->fd[_ - 1][0]);
		close(execd->fd[_][1]);
		_++;
	}
	_++;
	while (_ < data->cmd_ct - 1)
	{
		// dprintf(2, "tt closed end of read %lu. pipes, end of write %zu. pipes in %zu. process\n", _ - 1, _, execd->_);
		close(execd->fd[_ - 1][0]);
		close(execd->fd[_][1]);
		_++;
	}
}

char	**lsttoarr(t_list *lst)
{
	size_t		_;
	char		**arr;

	_ = 0;
	arr = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	while (lst)
	{
		arr[_] = lst->content;
		_++;
		lst = lst->next;
	}
	arr[_] = NULL;
	return (arr);
}

void	set_io(t_main *shell, t_execd *execd)
{
	if (!shell->cmds[execd->_].in)
	{
		if (execd->_ != 0) // not first
			dup2(execd->fd[execd->_ - 1][0], STDIN_FILENO);
	}
	else
	{
		if (execd->_ != 0) // not first
			close(execd->fd[execd->_ - 1][0]);
		dup2(shell->cmds[execd->_].in, STDIN_FILENO);
	}
	if (!shell->cmds[execd->_].out)
	{
		if ((execd->_ != (shell->cmd_ct - 1)) && (shell->cmd_ct != 1)) // not last
			dup2(execd->fd[execd->_][1], STDOUT_FILENO);	
	}
	else
	{
		if ((execd->_ != (shell->cmd_ct - 1)) && (shell->cmd_ct != 1))
			close(execd->fd[execd->_][1]);
		dup2(shell->cmds[execd->_].out, STDOUT_FILENO);
	}
	close_pipes(shell, execd);
	// dprintf(2, "> setted io\n");
}

// in fork here, so mallocable
void	list2env(t_main *shell)
{
	t_list const	*var = shell->vars;
	size_t			_;

	_ = 0;
	shell->env = malloc(sizeof(void *) * (ft_lstsize(shell->vars) + 1));
	while (var)
	{
		shell->env[_] = var->content;
		// printf("%s\n", shell->env[_]);
		_++;
		var = var->next;
	}
	
}

int		launch_program(t_main *shell, t_execd * execd)
{
	int		err;

	list2env(shell);
	err = execve(shell->cmds[execd->_].cmd, lsttoarr(shell->cmds[execd->_].args), shell->env);
	// if (shell->cmds[execd->_].args)
	// 	printf("command not found: %s\n", "a");
	return (err);
}

void	child(t_main *shell, t_execd *execd)
{
	// dup2(1, shell->cmds[execd->_].out);
	// dup2(0, shell->cmds[execd->_].in);
	/**
	 * must valid last given in/out-prompt (<, >, >>, <<);
	 * 
	 */
	set_io(shell, execd);
	if (execd->_)
	{
		// dprintf(2,"%s%d [%d, %d], %d is waiting\n", "mypid: ", getpid(), (execd->_), (shell->cmd_ct), execd->pids[execd->_ - 1]);
		// exit(1);
	}
	else
	{
		// dprintf(2,"%s%d [%d, %d], none is waiting\n", "mypid: ", getpid(), (execd->_), (shell->cmd_ct));
		// sleep(1);
		// printf("0 end\n");
	}
	// free all;
	// dprintf(2, "> launch_command %zu\n", execd->_);
	// shell->coms[(shell->cmds[execd->_].builtin_offset)].func(shell, execd);
	// printf("\n");
	exit(shell->coms[(shell->cmds[execd->_].builtin_offset)] \
			.func(shell, execd));
}

void	open_pipes(t_main *shell, t_execd *execd)
{
	size_t		_;

	_ = 0;
	execd->fd = malloc(sizeof(int *) * shell->cmd_ct - 1);
	while (_ < shell->cmd_ct - 1)
	{
		execd->fd[_] = malloc(sizeof(int) * 2);
		pipe(execd->fd[_++]);
	}
	
}

void	close_all_pipes_for_main(t_main *shell, t_execd *execd)
{
	size_t		_;

	_ = 0;
	while (_ < shell->cmd_ct - 1)
	{
		close(execd->fd[_][0]);
		close(execd->fd[_++][1]);
	}
}

void	wait_all(t_main *shell)
{
	size_t		_;

	_ = 0;
	while (_++ < shell->cmd_ct)
	{
		wait4(0, &shell->ex_stat, 0, NULL);
		// printf("> one process ended\n");
	}
	g_qsignal = 0;
	shell->ex_stat = WEXITSTATUS(shell->ex_stat);
}

void	reset(t_main *shell)
{
	shell->cmd_ct = 0;
	shell->current = 0;
	shell->has_cmd = 0;
	shell->_ = 0;
	shell->cmds = NULL;
}

void	exe_cute_cat(t_main *shell)
{
	t_execd		execd;
	char		*tmp;
	int			stock_fd[2];
	
	open_pipes(shell, &execd);
	// set_path(shell);
	execd.pids = malloc(sizeof(pid_t) * shell->cmd_ct);
	execd._ = 0;
	execd.pids[execd._] = 1;
	// printf("cmdsize: %d\n", shell->cmd_ct);
	if ((shell->cmd_ct == 1) && shell->cmds[0].builtin_offset)
	{
		// set_io(shell, &execd);
		if (shell->cmds[execd._].out)
		{
			stock_fd[0] = dup(STDOUT_FILENO);
			dup2(shell->cmds[execd._].out, STDOUT_FILENO);
		}
		if (shell->cmds[execd._].in)
		{
			stock_fd[1] = dup(STDIN_FILENO);
			dup2(shell->cmds[execd._].in, STDIN_FILENO);
		}
		shell->ex_stat = shell->coms[shell->cmds[0].builtin_offset].func(shell, &execd);
		if (shell->cmds[execd._].out)
		{
			close(shell->cmds[execd._].out);
			dup2(stock_fd[0], STDOUT_FILENO);
		}
		if (shell->cmds[execd._].in)
		{
			close(shell->cmds[execd._].in);
			dup2(stock_fd[1], STDIN_FILENO);
		}
	}
	else /* if (shell->cmds[0].cmd && !shell->cmds[0].builtin_offset) */
	{
		g_qsignal = 1;
		while (execd._ < shell->cmd_ct)
		{
			// printf("> one forked!\n");
			execd.pids[execd._] = fork();
			if (execd.pids[execd._] == 0)
				child(shell, &execd);
			execd._++;
		}
		--execd._;
		// printf("main wait pid %d\n", execd.pids[execd._]);
		close_all_pipes_for_main(shell, &execd);
		wait_all(shell);
		// printf("> main wait end.\n");
	}
	tmp = ft_itoa(shell->ex_stat);
	set(shell, ft_strsjoin((t_merge *[]){ \
									&(t_merge){"?", ft_strlen("?")},
									&(t_merge){"=", 1},
									&(t_merge){tmp, ft_strlen(tmp)}, NULL
								}));

	// printf("> log1 %i\n", shell->cmds[0].builtin_offset);
	// printf("> log2\n");
	reset(shell);
}

int	exe(t_com *coms, char *cmd)
{
	int		_;

	_ = 0;
	while (_ < CMD_COUNT)
	{
		if (!strcmp(cmd, coms[_].name))
		{
			// (free(cmd), coms[_].func(coms));
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
			|| (c == '?') || (c == '_')); // soru işareti sadece başta olacak
}

    // {"'$a'\"''$a''\"\"'$a'\"\"  '$a' $ $a \"\"  '$'  \"\"''\"'\"$a\"'\"$_\"'$_'-=$$\"$a\"$''$$$-$'a'4\"$a $a\"a'$a''a'\"v$a$av$\"$' ''$'a'\"$a\"'\"''\"31","aa0000=$a99$-$$$$$$$1$2$$11$$17"},


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
			('"' != c) && ('|' != c) && (' ' != c) && ('\t' != c) && ('\0' != c));
}

int	is_text(int c)
{
	return (('<' != c) && ('>' != c) && \
			('|' != c) && (' ' != c) && ('\t' != c) && ('\0' != c));
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

size_t	*len_dollar(t_main *data, char *var)
{
	size_t * const	db = malloc(sizeof(size_t) * 2); 

	db[1] = var_name_len(var);
	db[0] = ft_strlen(get_var_ref(data, var, db[1]));
	return (db); 
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
		// $, $$
		if (data->line[exp.index] == '\'')
			exp.len = len_string(data, exp.index + 1);
		else if (data->line[exp.index] == '"' && (free(exp.ptr), 1))
			exp.ptr = len_literal(data, exp.index + 1);
		else if (is_word(data->line[exp.index]) && !((data->line[exp.index] == \
									'$') && is_var(data->line[exp.index + 1])))
			exp.len = len_word(data, exp.index);
		// else if (data->line[exp.index] == '$' && (free(exp.ptr), 1))
		// {
		// 	exp.ptr = len_dollar(data, data->line + exp.index + 1);
		// 	printf("0: %zu, 1: %zu\n", exp.ptr[0], exp.ptr[1]);
		// }
		exp.index += exp.len + (size_t)exp.quote + exp.ptr[1];
		total += exp.len + exp.ptr[0];
		exp.len = 0;
		ft_bzero(exp.ptr, sizeof(size_t) * 2);
	}
	free(exp.ptr);
	// printf("len: %zu\n", total);
	return (total);
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

int		cpy_var(t_main *data, t_exp *exp, size_t offset)
{
	char		*var;
	const char	*name = ft_substr(data->line + offset, 0, exp->size = var_name_len(data->line + offset));

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
		exp->ret[exp->duo[1]++] = data->line[offset - 1]; // "$"
		return (free((void *)name), 0);
	}
	return (0);
}

size_t	*expander_exp(t_main *data, char *dst, size_t offset)
{
	t_exp	exp;

	offset++;
	exp.duo = malloc(sizeof(size_t) * 2);
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

t_turn	join_all(t_main *data, size_t offset)
{
	t_all			exp;
	// t_exp			dollar;
	t_turn			turn;
	char			*ptr;

	turn.buffer = calloc((len_all(data, offset) * sizeof(char)) + sizeof(char), 1);
	// dollar.duo = malloc(sizeof(size_t) * 2);
	// dollar.duo[0] = 0;
	// dollar.duo[1] = 0;
	// dollar.ret = turn.buffer;
	ptr = turn.buffer;
	turn.index = offset;
	exp.len = 0;
	exp.quote = 0;
	while (is_text(data->line[turn.index]) && !((data->line[turn.index] == '$') && \
			is_var(data->line[turn.index + 1])))
	{
		// printf("loop\n");
		if (data->line[turn.index] == '\'')
		{
			exp.quote = data->increases[data->line[turn.index]];
			exp.len = len_string(data, turn.index + 1) + 2;
			ft_memcpy(ptr, (data->line + turn.index + 1), exp.len - 2);
		}
		else if (data->line[turn.index] == '"') // else
		{
			exp.ptr = expander_exp(data, ptr, turn.index);
			ptr += exp.ptr[1];
			turn.index += exp.ptr[0];
			free(exp.ptr);
		}
		else if (is_word(data->line[turn.index]) && !((data->line[turn.index] == '$') && is_var(data->line[turn.index + 1]))) // else
		{
			exp.len = len_word(data, turn.index);
			ft_memcpy(ptr, (data->line + turn.index), exp.len);
		}
		// else if (data->line[turn.index] == '$')
		// {
		// 	cpy_var(data, &dollar, turn.index+1);
		// 	ptr += dollar.duo[1];
		// 	dollar.duo[1] = 0;
		// 	turn.index += dollar.size;
		// }
		turn.index += exp.len;
		ptr += exp.len - exp.quote;
		exp.quote = 0;
		exp.len = 0;
	}
	return (turn);
}

// int	is_text(int c)
// {
// 	return (('<' != c) && ('>' != c) && \
// 			('|' != c) && (' ' != c) && ('\0' != c));
// }

int			is_dollar(char *str)
{
	return (
		str[0] == '$' &&
		is_var(str[1])
	);
}
t_list	*ll_nod(t_list *node, int index)
{
	if (index < 0)
		return (0);
	while (index-- > 0 && node->next)
		node = node->next;
	if (index > -1)
		return (0);
	return (node);
}

int			start_with(char *str, char c)
{
	return (
		*str == c
	);
}

int			end_with(char *str, char c)
{
	while (*str)
		str++;
	return (
		*--str == c
	);
}

// void		free_2d(char **arr)
// {
// 	size_t		_;

// 	_ = 0;
// 	while (arr[_])
// 	{
// 		free(arr[_]);
// 		_++;
// 	}
// 	free(arr);
// }

void	lliter(t_list *lst, void (*f)(void *, void *), void *p)
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content, p);
		lst = lst->next;
	}
}

// void		push(void *cont, void *st)
// {
// 	ft_lstadd_back(&((t_join *)st)->nodes, ft_lstnew(((t_join *)st)->split[_]));
// }

size_t		arr2tolst(char **arr, t_list **lst)
{
	size_t		_;

	_ = 0;
	while (arr[_])
	{
		ft_lstadd_back(lst, ft_lstnew(arr[_]));
		_++;
	}
	return (_);
}

size_t		arr2size(char **arr)
{
	size_t		_;

	_ = 0;
	while (arr[_])
		_++;
	return (_);	
}

void		set_merge_flag(t_join *st, int val)
{
	if (val)
		st->merge_flag = 0;
	else
		st->merge_flag = 1;
}

t_turn2		join_all2(t_main *data, size_t offset)
{
	t_join		linker;
	t_turn		res;

	linker.merge_flag = 0;
	linker.nodes = NULL;
	linker.index = offset;
	while (is_text(data->line[linker.index]))
	{
		if (is_dollar(&data->line[linker.index]))
		{
			linker.var = get_var_ref(data, data->line + linker.index + 1, linker.len = var_name_len(data->line + linker.index + 1));
			linker.len++;
			if (linker.var)
			{
				linker.split = ft_split(linker.var, ' ');
				linker.arr_size = arr2size(linker.split);
				if (linker.var && !start_with(linker.var, ' ') && !start_with(linker.var, '\t') && linker.merge_flag)
				{
					linker.tmp = ft_strjoin(ft_lstlast(linker.nodes)->content, linker.split[0]);
					free(ft_lstlast(linker.nodes)->content);
					free(linker.split[0]);
					ft_lstlast(linker.nodes)->content = linker.tmp;
					arr2tolst(linker.split + 1, &linker.nodes);
					set_merge_flag(&linker, end_with(linker.split[linker.arr_size - 1], ' ') || end_with(linker.split[linker.arr_size - 1], '\t'));
				}
				else
					set_merge_flag(&linker, end_with(linker.split[arr2tolst( \
							linker.split, &linker.nodes) - 1], ' '));
				free(linker.split);
			}
		}
		else
		{
			res = join_all(data, linker.index);
			if (linker.merge_flag)
			{
				linker.tmp = ft_strjoin(ft_lstlast(linker.nodes)->content, res.buffer);
				free(ft_lstlast(linker.nodes)->content);
				free(res.buffer);
				ft_lstlast(linker.nodes)->content = linker.tmp;
			}
			else
			{
				ft_lstadd_back(&linker.nodes, ft_lstnew(res.buffer));
				linker.merge_flag = 1;
			}
			linker.len = res.index - linker.index;
		}
		linker.index += linker.len;
		linker.len = 0;
	}
	return ((t_turn2){.nodes = linker.nodes, .index = linker.index});
}

// int	set_value(t_main *data, char *str)
// {
// 		if (!data->flags[5])
// 			{
// 				// data->cmds = ;
// 			}
// }

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
		return (data->_ += 2,/*  pipe[data.heredoc], */ 4);
	else if (data->line[data->_] == '>' && data->line[data->_ + 1] == '>')
		return (data->_ += 2, *oflags |= O_APPEND | O_WRONLY | O_CREAT, 3);
	else if ('|' == data->line[data->_])
		return (data->has_cmd = 0,data->_++, data->current++, 0);
	else if ('\0' != data->line[data->_])
		return (data->has_cmd);
	return (7);
}

void	set_cmd(t_main *shell, char *string, int oflag)
{
	// printf("> set cmd\n");
	(void)oflag;
	shell->cmds[shell->current].cmd = string;
	ft_lstadd_back(&shell->cmds[shell->current].args, ft_lstnew(ft_strdup(string)));
	// printf("> set arg 0 on setting cmd: %s\n", shell->cmds[shell->current].args->content);
	shell->to_be = 1;
	shell->has_cmd = 1;
}

void	set_arg(t_main *shell, char *string, int oflag)
{
	// printf("> new arg %s\n", string);
	(void)oflag;
	ft_lstadd_back(&shell->cmds[shell->current].args, ft_lstnew(string));
}

void	prompt_heredoc(t_main *shell, char *label, int pipe[2])
{
	char		*buff;

	buff = NULL;
	buff = readline("> ");
	while (buff && strcmp(label, buff))
	{
		write(pipe[1], buff, strlen(buff));	
		write(pipe[1], "\n", 1);	
		free(buff);
		buff = readline("> ");
	}
	free(buff);
	write(pipe[1], "", 1);
	close(pipe[1]);
}

void	set_heredoc(t_main *shell, char *string, int oflag)
{
	int fd[2];

	pipe(fd);
	if (fd[0] < 0 || fd[1] < 0)
		return ;
	prompt_heredoc(shell, string, fd);
	shell->cmds[shell->current].in = fd[0];
	shell->to_be = shell->has_cmd;
}

void	set_in(t_main *shell, char *string, int oflag)
{

	const int fd = open(string, oflag, 0644);

	if (fd < 0)
		return ;
	shell->cmds[shell->current].in = fd;
	shell->to_be = shell->has_cmd;
}

void	set_out(t_main *shell, char *string, int oflag)
{
	const int fd = open(string, oflag, 0644);

	if (fd < 0)
		return ;
	shell->cmds[shell->current].out = fd;
	shell->to_be = shell->has_cmd;
}

void	none(t_main *shell, char *string, int oflag)
{
}

int		syntax_check(t_main *shell)
{
	size_t		_;
	t_syntax	syntax;

	syntax.undefined = 0;
	syntax.zero_pipe = 1;
	syntax.duplex = 0;
	syntax.simplex = 0;
	_ = 0;
	while (shell->line[_] == '\t' || shell->line[_] == ' ')
		_++;
	if (shell->line[_] == '\0')
		return (0);
	while (shell->line[_])
	{
		if (shell->line[_] == '\'')
		{
			if (syntax.duplex == 1)
			{
				syntax.duplex = 0;
				syntax.zero_pipe = 0;
				if (syntax.simplex)
					syntax.simplex = 0;
			}
			else if (syntax.duplex == 0)
				syntax.duplex = 1;
		}
		else if (shell->line[_] == '"')
		{
			if (syntax.duplex == 2)
			{
				syntax.duplex = 0;
				syntax.zero_pipe = 0;
				if (syntax.simplex)
					syntax.simplex = 0;
			}
			else if (syntax.duplex == 0)
				syntax.duplex = 2;
		}
		if (syntax.duplex)
		{
			(_)++;
			continue ;
		}
		if ((shell->line[_] == '>' && shell->line[_ + 1] != '>') || \
				(shell->line[_] == '<' && shell->line[_ + 1] != '<'))
		{
			if (!syntax.simplex)
				syntax.simplex = 1;
			else if (syntax.simplex == 3)
				syntax.simplex = 1;
			else
				break ;
			++_;
		}
		else if ((shell->line[_] == '>' && shell->line[_ + 1] == '>') || \
				(shell->line[_] == '<' && shell->line[_ + 1] == '<'))
		{
			if (!syntax.simplex)
				syntax.simplex = 2;
			else if (syntax.simplex == 3)
			{
				syntax.simplex = 2;
			}
			else
				break ;
			_ += 2;
		}
		else if (shell->line[_] == '|')
		{
			shell->cmd_ct++;
			if (!syntax.zero_pipe)
				syntax.zero_pipe = 1;
			else
				break ;
			if (!syntax.simplex)
				syntax.simplex = 3;
			else
				break ;
			++(_);
		}
		else
		{
			if (shell->line[_] == '\t' || shell->line[_] == ' ')
				++_;
			else
				syntax.zero_pipe = (syntax.simplex = (++_, 0));
			
		}
	}
	++shell->cmd_ct;
	// printf("%i %i %i %i\n", syntax.duplex, syntax.simplex, syntax.zero_pipe, syntax.undefined);
	return ((syntax.duplex << 0 ) | (syntax.simplex << 8) | \
			(syntax.zero_pipe << 16) | (syntax.undefined << 24));
}

void	print_syntax_err(int errs)
{
	if (errs & 0xff000000)
		printf("shell says: I don't know what you're trying to do\n");
	if (errs & 0x00ff0000)
		printf("shell says: syntax error near expected non-exist token before "
				"`|'\n");
	if (errs & 0x0000ff00)
		printf("shell says: syntax error near unexpected token after "
				"`|', `>', `<', `>>', `<<'\n");
	if (errs & 0x000000ff)
		printf("shell says: unexpected EOF while looking for matching "
				"`'', `\"'\n");
}

int		parser(t_main *data)
{
	MURMURTEST;

	t_turn2		res;
	t_list		*list;
	int			oflags;

	oflags = O_CLOEXEC;
	data->has_cmd = 0;
	data->syntax_err = syntax_check(data);
	if (data->syntax_err)
		return (print_syntax_err(data->syntax_err), reset(data), -1);
	if (!data->cmd_ct)
		return (0);
	data->cmds = calloc((data->cmd_ct), sizeof(t_cmd));
	// printf("> cmds size:%zu\n", data->cmd_ct);
	while (1)
	{
		while (' ' == data->line[data->_] || '\t' == data->line[data->_])
			data->_++;
		data->to_be = check_operation(data, &oflags);
		while (' ' == data->line[data->_] || '\t' == data->line[data->_])
			data->_++;
		// printf("> op:%i\n", data->to_be);
		// printf("> line: %s\n", data->line + data->_);
		if (data->to_be == 7)
			break ;
		list = (res = join_all2(data, data->_)).nodes;
		// printf("> joinall2: %p\n", list);
		void	print_tlist(t_list *head);
		// printf("> get-strings: %ic\n", res.index);
		// print_tlist(list);
		while (list)
		{
			// printf("> log5 %s\n", list->content);
			// printf("> log6 %d\n", data->to_be);
			(data->set_val[data->to_be])(data, list->content, oflags);
			list = list->next;
		}
		oflags = O_CLOEXEC;
		data->_ += res.index - data->_;
		// printf("> cursor moved: %s\n", data->line + data->_);
	}

	// printf("\n");
	set_path(data);
	for (size_t i = 0; i < (data)->cmd_ct; i++)
	{
		t_list		*arg = (data)->cmds[i].args;
		// printf("! %s\n", (data)->cmds[0].args->content);
		// printf("> path: %s\n", (data)->cmds[i].cmd);
		for (size_t i = 0; arg; i++)
		{
			// printf(">  arg[%zu]: %s\n", i, (char *)arg->content);
			arg = arg->next;
		}
		// printf("> in: %i\n", data->cmds[i].in);
		// printf("> out: %i\n", data->cmds[i].out);
	}
	exe_cute_cat(data);
	return (0);
}

void	f(t_list *node)
{
	printf("%s\n", (char *)node);
}

void	f2(t_list *node)
{
	free(node);
}

void	env2list(t_main *shell)
{
	size_t		_;

	_ = -1;
	while (shell->env[++_])
		set(shell, ft_strdup(shell->env[_]));
}

int	main(void)
{
	extern char 	**environ;
	t_main			data;
	struct termios	term1;

	if (tcgetattr(STDIN_FILENO, &term1) != 0)
		perror("tcgetattr() error");
	else
	{
		term1.c_cc[VQUIT] = _POSIX_VDISABLE;
		term1.c_lflag |= ECHOE;
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term1) != 0)
			perror("tcsetattr() error");
		if (tcgetattr(STDIN_FILENO, &term1) != 0)
			perror("tcgetattr() error");
	}

	data.env = environ;
	data.vars = NULL;
	set(&data, strdup("a=0000"));
	set(&data, strdup("?=0"));
	// printf("ENV: %s\n", cy = get(&data, "PATH"));
	// set(&data, strdup("PATH"), get(&data, "PATH"));
	// set(&data, strdup("PATH"), get(&data, "PATH"));
	// printf("a: %s\n", (((char **)data.vars->content)[1]));
	// printf("a: %s\n", get(&data, "array"));
	env2list(&data);
	// ft_lstiter(data.vars, (void (*)(void *))f);
	
	// ioctl(STDIN_FILENO, TIOCSTI, "minishell$ ``");
	// write(1, "\033[A", 3);

	// ft_memset(data.flags, 0, INT8_MAX);

	// tekte tanimla
	// data.fun = malloc(sizeof(size_t (*)(t_main *data, size_t offset)) * 3);
	ft_bzero(data.increases, INT8_MAX);
	data.increases['"'] = (char)2;
	data.increases['\''] = (char)2;
	// data.increases['$'] = (char)1;
	data.increases[0] = (char)0;
	data.cmds = NULL;
	data.coms = (t_com []){
		{"default", launch_program, NULL},
		{"echo", sh_echo, NULL},
		{"cd", sh_cd, NULL},
		{"pwd", sh_pwd, NULL},
		{"export", sh_export, NULL},
		{"unset", sh_unset, NULL},
		{"env", sh_env, NULL},
		{"exit", sh_exit, NULL},
	};
	data.cmd_ct = 0;
	data.current = 0;
	data.set_val[0] = set_cmd;
	data.set_val[1] = set_arg;
	data.set_val[2] = set_in;
	data.set_val[3] = set_out;
	data.set_val[4] = set_heredoc;
	data.set_val[5] = none;
	chdir("/home/mehmetap/sources/repos/projects/main/murmursh-copyxd");
	// printf("prog started %s\n", getcwd(NULL, 0));
	// data.coid = 1;
	signal(SIGINT, ctrl_c);
	// signal(SIGQUIT, coix);
	// signal(SIGTSTP, coix);
	// args = malloc(3 * sizeof(char *));
	// args[0] = strdup("/bin/ls");
	// args[1] = strdup("-la");
	// args[2] = 0;
			// getchar();
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
	g_qsignal = 0;
	while (1)
	{
		// printf("%s", );
		// rl_erase_empty_line = 1;

		// rl_already_prompted = 1;
		data.line = readline(GREEN PROMT RESET);
		add_history(data.line);
		if (data.line)
		{
			if (data.line[0] != 0)
			{
				data._ = 0;

				parser(&data);
				// system("valgrind --leak-check=full /Users/ahbasara/sources/repos/projects/main/murmursh-copyxd/program");
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
				printf(GREEN "" RESET);
				fflush(stdout);
				exit(0);
			}
			g_qsignal = 0;
			printf("\n");
		}
		// rl_on_new_line();
		// free(data.line);
	}
	ft_lstiter(data.vars, (void (*)(void *))f2);
	t_list *var;
	while (data.vars)
	{
		var = data.vars->next;
		free(data.vars);
		data.vars = var;
	}
}

/**
 * void	__attribute__((destructor))after_main()
 * {
 * 	pause();
 * }
 */
