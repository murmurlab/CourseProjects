/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:06:06 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/29 23:33:54 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_isnan(register double x)
{
	return (x != x);
}
double
	ft_fabs(register double x)
{
	if (ft_isnan(x))
		return (-(0.0 / 0.0));
	if (x < 0.0)
		return (x * -1.0);
	return (x);
}
