/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:07:58 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/27 13:00:09 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	even_philo(t_philo **philo)
{
	if (pthread_mutex_lock((*philo)->r_fork))
		return (1);
	if ((*philo)->data->death != 0)
	{
		pthread_mutex_unlock((*philo)->r_fork);
		return (0);
	}
	if (p_write(philo, "has taken right fork"))
		return (1);
	if (pthread_mutex_lock((*philo)->l_fork))
		return (1);
	if ((*philo)->data->death != 0)
	{
		pthread_mutex_unlock((*philo)->r_fork);
		pthread_mutex_unlock((*philo)->l_fork);
		return (0);
	}
	if (p_write(philo, "has taken left fork"))
		return (1);
	return (0);
}

int	no_even_philo(t_philo **philo)
{
	if (pthread_mutex_lock((*philo)->l_fork))
		return (1);
	if ((*philo)->data->death != 0)
	{
		pthread_mutex_unlock((*philo)->l_fork);
		return (0);
	}
	if ((*philo)->data->number_of_philo == 1)
		ft_usleep((*philo)->data->time_to_die + 1);
	if (p_write(philo, "has taken left fork"))
		return (1);
	if ((*philo)->data->number_of_philo != 1)
	{
		if (pthread_mutex_lock((*philo)->r_fork))
			return (1);
	}
	if ((*philo)->data->death != 0)
	{
		pthread_mutex_unlock((*philo)->l_fork);
		pthread_mutex_unlock((*philo)->r_fork);
		return (0);
	}
	if (p_write(philo, "has taken rigth fork"))
		return (1);
	return (0);
}

int	take_forks(t_philo **philo)
{
	if ((*philo)->data->death != 0)
		return (0);
	if ((*philo)->id % 2 == 0)
	{
		if (even_philo(philo))
			return (1);
	}
	else
	{
		if (no_even_philo(philo))
			return (1);
	}
	return (0);
}

void	free_forks(t_philo **philo, int flag)
{
	if (flag == 1)
		usleep((*philo)->data->time_to_eat * 1000);
	pthread_mutex_unlock((*philo)->l_fork);
	pthread_mutex_unlock((*philo)->r_fork);
}

int	eat(t_philo **philo)
{
	if ((*philo)->data->death != 0)
	{
		free_forks(philo, 0);
		return (0);
	}
	philo_update(philo);
	if ((*philo)->data->death != 0)
	{
		free_forks(philo, 0);
		return (0);
	}
	if (p_write(philo, GREEN"is eating"RESET))
		return (1);
	free_forks(philo, 1);
	if ((*philo)->data->death != 0)
		return (0);
	if (p_write(philo, BLUE"is sleeping"RESET))
		return (1);
	usleep((*philo)->data->time_to_sleep * 1000);
	if ((*philo)->data->death != 0)
		return (0);
	if (p_write(philo, YELLOW"is thinking"RESET))
		return (1);
	return (0);
}
