/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/27 18:37:18 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ps | grep './program' | awk '{print $1}' | xargs -I {} kill -9 {}
*/
#ifndef INCLUDE_H
# define INCLUDE_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */
/*
**  #  include "./linux.h"
** WSL keycodes
** #  define W 119
** #  define A 97
** #  define S 115
** #  define D 100
*/
#  define O_CLOEXEC __O_CLOEXEC

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */
/*
** #  include "./apple.h"
*/

// #  define VAR $
// #  define OUTF >
// #  define INF <
// #  define PIPE |
// #  define STR '
// #  define EXP "
// #  define HEREDOC <<
// #  define APPEND >>

# endif

#include "stdarg.h"

# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define RESET			"\x1B[0m"
# define VER			"1.0.0-b.3"
# define POSTFIX		"MURMURSH ["VER"]; "
# define SHELL_NAME 	""
# define PROMT SHELL_NAME POSTFIX

# define SHELLSAY		"shell says: "
# define OLDPWD_ERR_MSG	"OLDPWD not set"
# define IS_A_DIR_MSG	"Is a directory"
# define CMD_NOTFND_MSG	"command not found"
# define OLDPWD_ERR		335
# define CMD_NOTFND		334
# define IS_A_DIR		333

# define CMD_COUNT		8

# define INT8_MAX		127

# define KB				1024
# define MB				KB * 1024
# define GB				MB * 1024

# define MAX_CWD		KB * 64

# include "libft.h"

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "readline/readline.h"
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
// # include <sys/ioctl.h>
# include <termios.h>
# include <errno.h>
// # include <sys/types.h>
// # include <dirent.h>

typedef void			t_if;
typedef void			covid;

extern int		g_qsignal;

int		sh_echo();
int		sh_cd();
int		sh_pwd();
int		sh_export();
int		sh_unset();
int		sh_env();
int		sh_exit();

/**
 *  @struct t_order s_order
 *  @brief Filter structure 
 *	@memberof s_order::seq
 *	@var s_order::seq 
 */

typedef struct	s_export
{
	t_list		*arg;
	char		*discriminant;
	int			err;
	int			gerr;
	char		*to_set;
	char		validate;
}		t_export;

typedef struct	s_unset
{
	t_list	*find;
	t_list	*backup;
	t_list	*arg;
	int		gerr;
}		t_unset;


typedef struct	s_cd
{
	t_list		*param;
	int			err;
	int			backflag;
	char		*workdirs[2]; 
}		t_cd;

typedef struct	s_exp
{
	size_t	i;
	char	*ret;
	size_t	*duo;
	size_t	size;
	char	*var_value;
	char	*var_name;
}		t_exp;

// [0]-> line, [1]-> expanded

typedef	struct	s_all
{
	int		quote;
	size_t	len;
	size_t	index;
	size_t	*ptr;
	size_t	buff_index;
}		t_all;

// result
// jump index

typedef struct	s_turn
{
	char	*buffer;
	int		index;
}		t_turn;

// seperated strings
// jump index

typedef struct	s_turn2
{
	t_list	*nodes; 
	int		index; 
}		t_turn2;

// for merge
// for ambiguous redirect
// seperated strings
// line index
// pass len
// val dollar
// dollar splitted
// join tmp
// split len
typedef struct s_join
{
	int						merge_flag;
	int						is_multi_word;
	t_list					*nodes;
	int						index;
	size_t					len;
	char					*var;
	char					**split;
	char					*tmp;
	size_t					arr_size;
}		t_join;

/**
 * 0000 0001 '
 * 0000 0010 "
 * 0000 0100 |
 * 0000 1000 >
 * 0001 0000 <
 * 0010 0000 <<0
 * 0100 0000 >>
 * 1000 0000 
 */
typedef struct	s_syntax
{
	unsigned char		duplex;
	unsigned char		simplex;
	unsigned char		zero_pipe;
	unsigned char		undefined;
}		t_syntax;

struct	s_main;
struct	s_execd;

typedef struct	s_com
{
	char	*name;
	int		(*func)(struct s_main *, struct s_execd *);
	void	*data;
}		t_com;

typedef	struct	s_cmd
{
	int				io_err;
	int				ex;
	char			*cmd;
	t_list			*args;
	int				builtin_offset;
	int				in;
	int				out;
}		t_cmd;

/**
 * data.setval[0] = set_cmd;
 * data.setval[1] = set_arg;
 * data.setval[2] = set_in;
 * data.setval[3] = set_out;
*/
/**
 * 0	heredoc
 * 1	truncate
 * 2	infile
 * 3	append
 * 4	command exist
 * 5	any
 */

typedef	struct	s_main
{
	int				has_cmd;
	int				to_be;
	// t_list			*nodes;
	// t_list			*node;
	char			**env;
	char			cwd[MAX_CWD];
	// char			flags[INT8_MAX];
	void			(*coid)(int);
	// void			(*check_operation)();
	char			increases[INT8_MAX];
	void			*fun_ptr_void[4];
	int				(*set_val[6])(struct s_main *shell, char *string, int oflags);
	int				ex_stat;
	size_t			current;
	int				_;
	char			*line;
	int				syntax_err;
	t_com			*coms;
	t_cmd			*cmds;
	size_t			cmd_ct;
	t_list			*vars;
	// int				data;
}		t_main;

typedef	struct	s_merge
{
	char		*str;
	size_t		len;
}				t_merge;

typedef struct s_execd
{
	size_t		_;
	pid_t		*pids;
	int			**fd;
	int			*exs;
}				t_execd;

/* FUNCTIONS */
void	event_sigpipe(int signum);
void	err_free(int e, char *str);
void	dedect_text_type(t_main *shell, t_all *exp, t_turn *turn, char **ptr);
size_t	*len_dollar(t_main *data, char *var);
void		set_merge_flag(t_join *st, int val);
int		env2list(t_main *shell);
void	f(t_list *node);
void	f3(t_list *node);
void	list2env(t_main *shell);
void	e2(char *prefix, char *info, char *errmsg);
int	err(int e, char *str);
void	e(int err);
void	free_tab(char **tab);
size_t		arr2size(char **arr);
char	**lsttoarr(t_list *lst);
int		initialization(t_main *shell);
void	no_del(void *);
int		prompt_heredoc(char *label, int pipe[2]);
char	*check_cmd(char *cmd, char *path);
void	syntax_other(t_main *shell, t_syntax *syntax, size_t *_);
t_list	*lst_filter(t_list *nod, int f(t_list *node_iterate, void *data_compare), void *data);
int	check_operation(t_main *data, int *oflags);
t_list	*lst_filter_prev(t_list *nod, int f(t_list *node_iterate, void *data_compare), void *data);
size_t		arr2tolst(char **arr, t_list **lst);
int		strccmp(const char *s1, const char *s2, char ch);
void	print_syntax_err(int errs);
char	*ft_strsjoin(t_merge *strs[]);
int		syntax_sarrow(t_syntax *syntax, size_t *_);
int		choose(t_main *shell, t_syntax *syntax, size_t *_);
int		syntax_check(t_main *shell);
int		syntax_pipe(t_main *shell, t_syntax *syntax, size_t *_);
int		syntax_darrow(t_syntax *syntax, size_t *_);
void	syntax_dquote(t_syntax *syntax);
void	syntax_squote(t_syntax *syntax);
void	set_path(t_main *shell);
void	search_builtins(t_main *shell, int cmd_off);
int		none(t_main *shell, char *string, int oflag);
void	f2(t_list *node);
void	ex(t_main *shell);
void	if_cmd(t_main *shell, size_t _);
int		run(t_main *data);
void	reset(t_main *shell, t_execd *execd);
void	del(void *_);
void	clear_pipes(int **pipes, size_t cmd_ct);
void	clear_cmds(t_cmd *cmds, size_t cmd_ct);
void	if_path(t_main *shell, size_t _);
int		set_all(t_main *shell);
char	*resolve_cmd(t_main *shell, char *string, size_t _);
int		set_in(t_main *shell, char *string, int oflag);
int		set_out(t_main *shell, char *string, int oflag);
int		set_arg(t_main *shell, char *string, int oflag);
int		set_cmd(t_main *shell, char *string, int oflag);
int		set_heredoc(t_main *shell, char *string, int oflag);
void	coix(int sig);
void	tcsa();
covid	ctrl_c(int sig);
size_t	len_word(t_main *data, size_t offset);
size_t	len_string(t_main *data, size_t offset);
size_t	var_name_len(char *start);
size_t	len_all(t_main *data, size_t offset);
size_t	*expander_exp(t_main *data, char *dst, size_t offset);
t_turn	join_all(t_main *shell, size_t offset);
size_t	*len_literal(t_main *data, size_t offset);
void		seperation(t_join *linker);
void		adhesion(t_join *linker);
void		add_text(t_join *linker, t_main *shell, t_turn *res);
t_turn2		expander(t_main *shell, size_t offset);
void		add_dollar(t_join *linker, t_main *shell);
void	close_pipes(t_main *data, t_execd *execd);
int		launch_program(t_main *shell, t_execd * execd);
void	wait_all(t_main *shell, t_execd *execd);
void	child(t_main *shell, t_execd *execd);
void	set_io(t_main *shell, t_execd *execd);
void	close_all_pipes_for_main(t_main *shell, t_execd *execd);
void	exe_cute_cat(t_main *shell);
void	multi_exe(t_main *shell, t_execd *execd);
void	open_pipes(t_main *shell, t_execd *execd);
void	restore_io(t_main *shell, t_execd *execd, int *stock_fd);
void	change_io(t_main *shell, t_execd *execd, int *stock_fd);
int		cpy_var(t_main *data, t_exp *exp, size_t offset);
char	*get_var_ref(t_main *data, char *var_name, size_t len);
char	*get_ref(t_main *data, char const *var);
int		set(t_main *shell, char *duplex);
char	*get(t_main *data, char const *var);
int		sh_env(t_main *shell, t_execd *execd);
int		sh_unset(t_main *shell, t_execd *execd);
void	unset_arg(t_main *shell, t_unset *unset);
int		sh_export(t_main *shell, t_execd *execd);
void	export_arg(t_main *shell, t_export *export);
int		sh_cd(t_main *shell, t_execd *execd);
void	update_pwd(t_main *shell, t_cd *cd);
void	set_working_dirs(t_main *shell, char *pwd, char *oldpwd);
int		sh_echo(t_main *shell, t_execd *execd);
int		sh_pwd(t_main *shell, t_execd *execd);
int		sh_exit(t_main *shell, t_execd *execd);
int			is_dollar(char *str);
int			start_with(char *str, char c);
int	check(t_list *node, void *cmp);
int			end_with(char *str, char c);
int	is_text(int c);
int	is_word(int c);
int	is_var(int c);
int			is_valid_value(char *id);
int			is_valid_identifier(char *id);
int			env2list(t_main *shell);
void		close_all_pipes_for_main(t_main *shell, t_execd *execd);
void		child(t_main *shell, t_execd *execd);
char		*get_ref(t_main *data, char const *var);
int			initialization(t_main *shell);
int			launch_program(t_main *shell, t_execd * execd);
void		print_syntax_err(int errs);
int			set_all(t_main *shell);
t_turn		join_all(t_main *data, size_t offset);
size_t		*expander_exp(t_main *data, char *dst, size_t offset);
char		*get_var_ref(t_main *data, char *var_name, size_t len);
size_t		len_all(t_main *data, size_t offset);
int			is_var(int c);
int			is_text(int c);
size_t		var_name_len(char *start);
int			check(t_list *node, void *cmp);
int			set(t_main *data, char *duplex);
int			run(t_main *shell);
char*		get();
void		exe_cute_cat();
char		*check_cmd(char *cmd, char *path);
char		*ft_strsjoin(t_merge *strs[]);
char		*ft_strcpy(char *dest, char *src);
void		resolve(char *string);
void		set_path(t_main *data);
int			err(int e, char *str);
int			syntax_check(t_main *shell);
t_list		*lst_filter(t_list *nod, int f(t_list *node_iterate, void *data_compare), void *data);
void		f(t_list *node);


# include "testing.h"
void	list_cmds(t_main *data);

#endif
