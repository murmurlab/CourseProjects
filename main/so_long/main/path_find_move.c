/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:39:12 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/06 10:11:30 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libs/libft/libft.h"

void	ft_moveright(char ***map, int *x, int *y)
{
	if ((*map)[*x][*y] == 'C')
		(*map)[*x][*y + 1] = 'C';
	else
		(*map)[*x][*y + 1] = 'E';
	(*map)[*x][*y] = '1';
	*y = *y + 1;
}

void	ft_moveleft(char ***map, int *x, int *y)
{
	if ((*map)[*x][*y] == 'C')
		(*map)[*x][*y - 1] = 'C';
	else
		(*map)[*x][*y - 1] = 'E';
	(*map)[*x][*y] = '1';
	*y = *y - 1;
}

void	ft_moveup(char ***map, int *x, int *y)
{
	if ((*map)[*x][*y] == 'C')
		(*map)[*x - 1][*y] = 'C';
	else
		(*map)[*x - 1][*y] = 'E';
	(*map)[*x][*y] = '1';
	*x = *x - 1;
}

void	ft_movedown(char ***map, int *x, int *y)
{
	if ((*map)[*x][*y] == 'C')
		(*map)[*x + 1][*y] = 'C';
	else
		(*map)[*x + 1][*y] = 'E';
	(*map)[*x][*y] = '1';
	*x = *x + 1;
}
