/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:11:51 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/30 09:42:21 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	set_working_dirs(t_main *shell, char *pwd, char *oldpwd)
{
	set(shell, ft_strsjoin((t_merge *[]){
			&(t_merge){"OLDPWD", 6},
			&(t_merge){"=", 1}, &(t_merge){oldpwd,
			ft_strlen(oldpwd)}, NULL}));
	set(shell, ft_strsjoin((t_merge *[]){
			&(t_merge){"PWD", 3},
			&(t_merge){"=", 1}, &(t_merge){pwd,
			ft_strlen(pwd)}, NULL}));
}

void	update_pwd(t_main *shell, t_cd *cd)
{
	char const	*tmp = get_ref(shell, "OLDPWD");

	getcwd(shell->cwd, MAX_CWD);
	cd->workdirs[0] = get_ref(shell, "PWD");
	if (tmp)
		cd->workdirs[1] = ft_strdup(tmp);
	else
		cd->workdirs[1] = ft_strdup("");
	if (cd->backflag)
		set_working_dirs(shell, cd->workdirs[1], cd->workdirs[0]);
	else
		set_working_dirs(shell, shell->cwd, cd->workdirs[0]);
	free(cd->workdirs[1]);
}

int	cd_util(t_cd *cd, t_main *shell)
{
	cd->backflag = 0;
	cd->err = chdir(get_ref(shell, "HOME"));
	if (cd->err)
		perror(SHELLSAY"cd");
	else
		update_pwd(shell, cd);
	return (cd->err);
}

int	sh_cd(t_main *shell, t_execd *execd)
{
	t_cd					cd;

	cd.param = shell->cmds[execd->_].args->next;
	if (cd.param)
	{
		cd.backflag = !ft_strcmp("-", cd.param->content);
		if (cd.backflag)
			cd.err = chdir(get_ref(shell, "OLDPWD"));
		else
			cd.err = chdir(cd.param->content);
		if (!get_ref(shell, "OLDPWD") && cd.err && cd.backflag)
			err_free(OLDPWD_ERR, ft_strjoin("cd: ", cd.param->content));
		else if (cd.err)
			err_free(errno, ft_strjoin("cd: ", cd.param->content));
		else
			update_pwd(shell, &cd);
		if (cd.err)
			return (1);
		return (cd.err);
	}
	else
		return (cd_util(&cd, shell));
	return (1);
}
