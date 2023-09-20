/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:06:47 by ahbasara          #+#    #+#             */
/*   Updated: 2023/09/20 12:18:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define nodeNext(node) node + 8

#include "include.h"

void	load_nums(void)
{
}

int	main(void)
{
	void	**node1;
	void	**node2;
	void	**node3;

	node1 = lpnew(0);
	node2 = lpnew(0);
	node3 = lpnew(0);
	node1[0] = (void *)444444;
	node1[1] = node2;
	node2[0] = (void *)333331;
	node2[1] = node3;
	node3[0] = (void *)999999;
	node3[1] = NULL;
	p("|%d|\n", lpnod(node1, 2)[0]);
	return (0);
}
