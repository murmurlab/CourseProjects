/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:53:09 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/20 12:31:51 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double(t_variables *var, char **str, int check)
{
	int	i;

	if (check == 0)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free (str);
	}
	else if (check == 1)
	{
		free(var->c_l);
		free(var->tmp);
	}
	else
	{
		free(var->c_l);
		free(var->tmp);
		free(var);
	}
}

void	no_way(t_stack **stack, int *x, int *y)
{
	t_stack	*tmp;

	tmp = ft_stack_pop(stack);
	*x = tmp->x;
	*y = tmp->y;
	free(tmp);
}

void	var_init(t_variables *var, int *is_valid, char **map, char *map_name)
{
	var->tmp_map = create_tmp_map(map_name);
	var->c_l = c_locate(map, map_name);
	var->tmp = c_locate(map, map_name);
	*is_valid = path_find(var->tmp_map, var->c_l, var->p_l);
	free_double(var, var->tmp_map, 0);
}

int	path_find(char **tmp_map, t_stack *c_l, t_stack *p_l)
{
	t_stack	*stack;

	stack = ft_stack_new(c_l->x, c_l->y);
	while (stack != NULL)
	{
		if (is_turnout(tmp_map, c_l->x, c_l->y) > 1)
			ft_stack_push(&stack, ft_stack_new(c_l->x, c_l->y));
		if (tmp_map[c_l->x][c_l->y + 1] == '0')
			ft_moveright(&tmp_map, &c_l->x, &c_l->y);
		else if (tmp_map[c_l->x][c_l->y - 1] == '0')
			ft_moveleft(&tmp_map, &c_l->x, &c_l->y);
		else if (tmp_map[c_l->x + 1][c_l->y] == '0')
			ft_movedown(&tmp_map, &c_l->x, &c_l->y);
		else if (tmp_map[c_l->x - 1][c_l->y] == '0')
			ft_moveup(&tmp_map, &c_l->x, &c_l->y);
		else
			no_way(&stack, &c_l->x, &c_l->y);
		if (c_l->x == p_l->x && c_l->y == p_l->y)
		{
			ft_stack_clear(&stack);
			return (1);
		}
	}
	return (0);
}
//is valid always will be start from one.

int	is_possible(char **map, char *map_name, int is_valid)
{
	t_variables	*var;

	var = malloc(sizeof(t_variables));
	var->c_counter = collectable_counter(map, map_name);
	var->p_l = p_locate(map);
	while (var->c_counter != 0)
	{
		var_init(var, &is_valid, map, map_name);
		if (is_valid == 1)
		{
			map[var->tmp->x][var->tmp->y] = '0';
			var->c_counter--;
			free_double(var, var->tmp_map, 1);
		}
		else
			break ;
	}
	free(var->p_l);
	if (var->c_counter > 0)
	{
		free_double(var, var->tmp_map, 2);
		return (0);
	}
	free(var);
	return (1);
}
