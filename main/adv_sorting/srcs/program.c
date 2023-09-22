/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:13:33 by ahbasara          #+#    #+#             */
/*   Updated: 2023/09/21 23:08:58 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <time.h>
#include <stdio.h>
	// push swap kolay ve kisa bir proje

void	load_nums(void)
{
}

int	main(void)
{
	int		i;
	char	*str;
	t_link	genesis;
	t_link	tmp;

	genesis = lp_new(strcln("asarsars"));
	i = 0;
	while (i < 100)
	{
		str = malloc(10);
		sprintf(str, "axxa%d", i);
		tmp = lp_new(str);
		lp_push(&genesis, tmp);
		i++;
	}
	i = 0;
	while (i < 100 +1)
	{
		p("%s\n", lp_nod(genesis, 0)[0]);
		lp_pop(&genesis, freedom);
		i++;
	}
	// freedom(genesis);
	return (0);
}
