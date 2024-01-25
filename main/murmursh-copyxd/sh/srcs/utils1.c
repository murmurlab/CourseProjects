#include "include.h"

int		env2list(t_main *shell)
{
	size_t		_;

	_ = -1;
	while (shell->env[++_])
	{
		if (set(shell, ft_strdup(shell->env[_])))
			return (1);
	}
	return (0);
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

void	list2env(t_main *shell)
{
	t_list const	*var = shell->vars;
	size_t			_;

	_ = 0;
	shell->env = malloc(sizeof(void *) * (ft_lstsize(shell->vars) + 1));
	while (var)
	{
		shell->env[_] = var->content;
		_++;
		var = var->next;
	}
	shell->env[_] = NULL;
}

void	free_tab(char **tab)
{
	size_t		_;

	_ = 0;
	while (tab[_])
		free(tab[_++]);
	free(tab);
}

size_t		arr2size(char **arr)
{
	size_t		_;

	_ = 0;
	while (arr[_])
		_++;
	return (_);	
}
