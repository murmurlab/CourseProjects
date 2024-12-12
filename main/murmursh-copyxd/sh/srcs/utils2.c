/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:08:24 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/29 16:08:57 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	f(t_list *node)
{
	printf("%s\n", (char *)node);
}

void	f3(t_list *node)
{
	printf("declare -x %s\n", (char *)node);
}

void	e2(char *prefix, char *info, char *errmsg)
{
	size_t const		prefix_l = ft_strlen(prefix);
	size_t const		info_l = ft_strlen(info);
	size_t const		errmsg_l = ft_strlen(errmsg);
	size_t const		total_l = prefix_l + info_l + errmsg_l + 3;
	char const *const	total = ft_strsjoin((t_merge *[]){\
			&(t_merge){prefix, prefix_l},
			&(t_merge){info, info_l},
			&(t_merge){": ", 2},
			&(t_merge){errmsg, errmsg_l},
			&(t_merge){"\n", 1},
			NULL});

	write(2, total, total_l);
	free((void *)total);
}

void	err_free(int e, char *str)
{
	err(e, str);
	free(str);
}

int	err(int e, char *str)
{
	errno = e;
	if (e == IS_A_DIR)
		e2(SHELLSAY, str, IS_A_DIR_MSG);
	else if (e == CMD_NOTFND)
		e2(SHELLSAY, str, CMD_NOTFND_MSG);
	else if (e == INVALID_ID)
		e2(SHELLSAY, str, INVALID_ID_MSG);
	else if (e == OLDPWD_ERR)
		e2(SHELLSAY, str, OLDPWD_ERR_MSG);
	else if (e == ENOENT)
		e2(SHELLSAY, str, strerror(ENOENT));
	else if (e == EACCES)
		e2(SHELLSAY, str, strerror(EACCES));
	else if (e == EPERM)
		e2(SHELLSAY, str, strerror(EPERM));
	else
		e2(SHELLSAY, str, strerror(errno));
	return (0);
}
