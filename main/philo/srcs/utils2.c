/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:30:43 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/11 22:40:07 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	monitoring_sh_1(t_order *restrict self)
{
	printf("%ld %d has taken a fork\n", diff(self) / 1000, self->seq);
}

void	monitoring_sh_2(t_order *restrict self)
{
	printf("%ld %d is sleeping\n", diff(self) / 1000, self->seq);
}

void	monitoring_sh_3(t_order *restrict self)
{
	printf("%ld %d is thinking\n", diff(self) / 1000, self->seq);
}

void	monitoring_sh_4(t_order *restrict self)
{
	printf("%ld %d is eating\n", diff_(self) / 1000, self->seq);
}

int	monitoring_sh(t_order *restrict self, int fun_sel)
{
	pthread_mutex_lock(&self->cntl->ct_mut);
	if (self->cntl->stop)
		return (pthread_mutex_unlock(&self->cntl->ct_mut), 1);
	pthread_mutex_lock(&self->cntl->print_mut);
	self->cntl->monitoring_funs[fun_sel](self);
	pthread_mutex_unlock(&self->cntl->print_mut);
	pthread_mutex_unlock(&self->cntl->ct_mut);
	return (0);
}
