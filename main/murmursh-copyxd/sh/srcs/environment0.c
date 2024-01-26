#include "include.h"

// Bash --posix: [a-zA-Z_][0-9a-zA-Z_]*

void	export_arg(t_main *shell, t_export *export)
{
	export->discriminant = ft_strchr(export->arg->content, '=');
	if (export->discriminant)
	{
		if (export->discriminant == export->arg->content || is_valid_value(export->discriminant + 1))
			export->gerr = (export->err = 1);
		*export->discriminant = '\0';
	}
	export->validate = is_valid_identifier(export->arg->content);
	if (export->discriminant)
	{
		*export->discriminant = '=';
		export->to_set = export->arg->content;
	}
	else
		export->to_set = ft_strjoin(export->arg->content, "=");
	if (!export->err && !export->validate)
		set(shell, export->to_set);
	else
		printf("export: `%s': not a valid identifier\n", (char *)export->arg->content);
	export->arg = export->arg->next;
	export->err = 0x0;
}

int		sh_export(t_main *shell, t_execd *execd)
{
	t_export		export;
	
	export.err = 0;
	export.gerr = 0;
	export.arg = shell->cmds[execd->_].args->next;
	if (export.arg)
	{
		while (export.arg)
			export_arg(shell, &export);
	}
	else
		ft_lstiter(shell->vars, (void (*)(void *))f3);
	return (export.gerr);
}

void	unset_arg(t_main *shell, t_unset *unset)
{
	unset->find = lst_filter_prev(shell->vars, check, unset->arg->content);
	if (is_valid_identifier(unset->arg->content))
		unset->gerr = (printf("export: `%s': not a valid identifier\n", (char *)unset->arg->content), 1);
	if (!unset->find)
	{
		unset->arg = unset->arg->next;
		return ;
	}
	if (unset->find == shell->vars)
	{
		shell->vars = unset->find->next;
		ft_lstdelone(unset->find, del);
	}
	else
	{
		unset->backup = unset->find->next;
		unset->find->next = unset->find->next->next;
		ft_lstdelone(unset->backup, del);
	}
	unset->arg = unset->arg->next;
}

int		sh_unset(t_main *shell, t_execd *execd)
{
	t_unset		unset;

	unset.arg = shell->cmds[execd->_].args->next;
	unset.gerr = 0;
	while (unset.arg)
		unset_arg(shell, &unset);
	return (unset.gerr);
}

int		sh_env(t_main *shell, t_execd *execd)
{
	(void)execd;
	ft_lstiter(shell->vars, (void (*)(void *))f);
	return (0);
}
