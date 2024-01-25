#include "include.h"

void		add_text(t_join *linker, t_main *shell, t_turn *res)
{
	*res = join_all(shell, linker->index);
	if (linker->merge_flag)
	{
		linker->tmp = ft_strjoin(ft_lstlast(linker->nodes)->content, res->buffer);
		free(ft_lstlast(linker->nodes)->content);
		free(res->buffer);
		ft_lstlast(linker->nodes)->content = linker->tmp;
	}
	else
	{
		ft_lstadd_back(&linker->nodes, ft_lstnew(res->buffer));
		linker->merge_flag = 1;
	}
	linker->len = res->index - linker->index;
}

void		adhesion(t_join *linker)
{
	linker->tmp = ft_strjoin(ft_lstlast(linker->nodes)->content,
							linker->split[0]);
	free(ft_lstlast(linker->nodes)->content);
	free(linker->split[0]);
	ft_lstlast(linker->nodes)->content = linker->tmp;
	arr2tolst(linker->split + 1, &linker->nodes);
	set_merge_flag(linker,
		(
			end_with(
				linker->split[linker->arr_size - 1], ' '
			)
			||
			end_with(
				linker->split[ \
				linker->arr_size - 1], '\t'
			)
		)
	);
}

void		seperation(t_join *linker)
{
	set_merge_flag(linker,
		end_with(
			linker->split[
				arr2tolst(linker->split, &linker->nodes) - 1
			]
			, ' '
		)
	);
}

void		add_dollar(t_join *linker, t_main *shell)
{
	linker->var = get_var_ref(shell, shell->line + linker->index + 1, linker->len = var_name_len(shell->line + linker->index + 1));
	linker->len++;
	if (!linker->var || linker->var[0] == 0 )
		return ;
	linker->split = ft_split(linker->var, ' ');
	if (!linker->split)
		return ;
	linker->arr_size = arr2size(linker->split);
	if (linker->var && (!start_with(linker->var, ' ') || \
		!start_with(linker->var, '\t')) && linker->merge_flag)
		adhesion(linker);
	else
		seperation(linker);
	free(linker->split);
}

t_turn2		expander(t_main *shell, size_t offset)
{
	t_join		linker;
	t_turn		res;

	linker.merge_flag = 0;
	linker.nodes = NULL;
	linker.index = offset;
	while (is_text(shell->line[linker.index]))
	{
		if (is_dollar(&shell->line[linker.index]))
			add_dollar(&linker, shell);
		else
			add_text(&linker, shell, &res);
		linker.index += linker.len;
		linker.len = 0;
	}
	return ((t_turn2){.nodes = linker.nodes, .index = linker.index});
}
