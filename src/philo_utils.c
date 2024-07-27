/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:51:08 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/26 12:43:31 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	philo_update(t_philo **philo)
{
	(*philo)->eat_times++;
	(*philo)->time_to_die = get_time() + \
		(*philo)->data->time_to_die - (*philo)->data->start;
}

long	get_time(void)
{
	struct timeval	time;
	long			time_ms;

	if (gettimeofday(&time, NULL))
		return (0);
	time_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_ms);
}

long	ft_usleep(int time)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}
