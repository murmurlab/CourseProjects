#include "include.h"

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
