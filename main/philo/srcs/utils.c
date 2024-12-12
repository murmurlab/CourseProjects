/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:30:43 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/11 06:05:11 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	ft_get_local_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	ft_usleep(int time)
{
	int	start;

	start = ft_get_local_time();
	while (ft_get_local_time() - start < time * 1000)
		usleep(100);
}

void	ext(t_order *self)
{
	pthread_mutex_unlock(&self->cntl->f_mut[idx(self->idx + 1, \
						self->cntl->consts[0])]);
	pthread_mutex_unlock(&self->cntl->f_mut[self->idx]);
	free(self);
}

int	idx(int index, int len)
{
	return ((index + len) % len);
}

int	eat(t_order *restrict self)
{
	if (monitoring_sh(self, 3))
		return (1);
	ft_usleep(self->cntl->consts[2]);
	return (0);
}
