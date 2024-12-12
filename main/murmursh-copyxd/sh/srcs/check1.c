/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:38:18 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/29 17:47:19 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_dollar(char *str)
{
	return (
		str[0] == '$' && \
		is_var(str[1])
	);
}

int	start_with(char *str, char c)
{
	return (
		*str == c
	);
}

int	end_with(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
		str++;
	return (
		*--str == c
	);
}

int	check(t_list *node, void *cmp)
{
	if (strccmp(node->content, cmp, '='))
		return (1);
	return (0);
}

int	i_space(char character)
{
	return (
		' ' == character || \
		'\t' == character || \
		'\v' == character || \
		'\f' == character || \
		'\r' == character
	);
}
