#include "include.h"

void	f(t_list *node)
{
	printf("%s\n", (char *)node);
}

void	f3(t_list *node)
{
	printf("declare -x %s\n", (char *)node);
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

int	err(int e, char *str)
{
	char		*tmp;
	
	errno = e;
	if (e == IS_A_DIR)
	{
		e2(SHELLSAY);
		e2(str);
		e2(IS_A_DIR_MSG);
	}
	else if (e == CMD_NOTFND)
	{
		e2(SHELLSAY);
		e2(str);
		e2(CMD_NOTFND_MSG);
	}

	else if (e == ENOENT)
	{
		perror(tmp = ft_strjoin(SHELLSAY, str));
		free(tmp);
	}
	else if (e == EACCES)
	{
		perror(tmp = ft_strjoin(SHELLSAY, str));
		free(tmp);
	}
	else if (e == EPERM)
	{
		perror(tmp = ft_strjoin(SHELLSAY, str));
		free(tmp);
	}
	else
	{
		perror(tmp = ft_strjoin(SHELLSAY, str));
		free(tmp);
	}
	return (0);
}
