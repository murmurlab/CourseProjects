/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:56:59 by ahbasara          #+#    #+#             */
/*   Updated: 2023/12/04 16:02:40 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_list	*lst_filter(t_list *nod, int f(t_list *node_iterate, void *data_compare), void *data)
{
	while (nod)
	{
        if (f(nod, data))
            return (nod);
		nod = nod->next;
	}
	return (NULL);
}