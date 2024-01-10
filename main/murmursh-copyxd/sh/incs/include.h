/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/10 19:04:57 by ahbasara         ###   ########.fr       */
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

# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define RESET			"\x1B[0m"
# define POSTFIX		"$ "
# define SHELL_NAME 	"minishell"
# define PROMT SHELL_NAME POSTFIX

# define IS_A_DIR_MSG	": Is a directory"

# define IS_A_DIR		333

# define CMD_COUNT		8

# define INT8_MAX		127

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
// # include <termios.h>
# include <errno.h>
// # include <sys/types.h>
// # include <dirent.h>

# ifndef TEST
#  define TEST 0
# endif

void	run_test();

typedef void			t_if;
typedef void			covid;

int	sh_echo();
int	sh_cd();
int	sh_pwd();
int	sh_export();
int	sh_unset();
int	sh_env();
int	sh_exit();

/**
 *  @struct t_order s_order
 *  @brief Filter structure 
 *	@memberof s_order::seq
 *	@var s_order::seq 
 */

typedef struct	s_exp
{
	size_t	i;
	char	*ret; //
	size_t	*duo;
	size_t	size;
	char	*var_value;
	char	*var_name;
}		t_exp;

typedef	struct	s_all
{
	int		quote;
	size_t	len;
	size_t	index;
	size_t	*ptr; // [0]-> line, [1]-> expanded
	size_t	buff_index;
}		t_all;

typedef struct	s_turn
{
	char	*buffer; // result
	int		index; // jump index
}		t_turn;

typedef struct s_join
{
	int						merge_flag; // for merge
	int						is_multi_word; // for ambiguous redirect
	t_list					*nodes; // seperated strings
	int						index; // line index
	size_t					len; // pass len
	char					*var; // val dollar
	char					**split; // dollar splitted
	char					*tmp; // join tmp
	size_t					arr_size; // split len
}		t_join;

typedef struct	s_com
{
	char *name;
	int (*func)();
	void	*data;
}		t_com;

typedef	struct	s_cmd
{
	char			*cmd;
	char			**args;
	int				in;
	int				out;
}		t_cmd;

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
	char			flags[INT8_MAX];
	void			(*coid)(int);
	// void			(*check_operation)();
	char			increases[INT8_MAX];
	int				_;
	char			*line;
	t_com			*coms;
	t_cmd			*cmds;
	size_t			cmd_ct;
	t_list			*vars;
	int				data;
}		t_main;

typedef	struct	s_merge
{
	char		*str;
	size_t		len;
}				t_merge;

typedef struct
{
	size_t		_;
	pid_t		*pids;
	int			fd[4][2];
}				t_execd;

/* FUNCTIONS */
t_turn	join_all(t_main *data, size_t offset);
size_t	*expander_exp(t_main *data, char *dst, size_t offset);
char	*get_var_ref(t_main *data, char *var_name, size_t len);
size_t	len_all(t_main *data, size_t offset);
int		is_var(int c);
int		is_text(int c);
size_t	var_name_len(char *start);
int		check(t_list *node, void *cmp);
int		set(t_main *data, char const * name, char const * value);
int		parser();
char*	get();
t_list	*lst_filter();
void	exe_cute_cat();
char	*check_cmd(char *cmd, char *path);
char	*ft_strsjoin(t_merge *strs[]);
char	*ft_strcpy(char *dest, char *src);
void	resolve(char *string);
void	set_path(t_main *data);
int		err(int e, char *str);
t_list	*join_all2(t_main *data, size_t offset);

#endif
