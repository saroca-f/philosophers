/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:14:05 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/25 20:08:03 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	check_death(t_data *data, t_philo **current_philo)
{
	int			i;
	int			j;
	uint64_t	now;

	i = 0;
	j = 0;
	while (i < data->number_of_philo && data->death == 0)
	{
		now = get_time() - data->start;
		(*current_philo) = &data->philosopher[i];
		if (now > (*current_philo)->time_to_die)
		{
			data->death = 1;
			break ;
		}
		if ((*current_philo)->eat_times >= data->max_eat)
			j++;
		if (j == data->number_of_philo && data->max_eat > 0)
		{
			data->death = 2;
			break ;
		}
		i++;
	}
}

void	*super(void *arg)
{
	t_data		*data;
	uint64_t	now;
	t_philo		*current_philo;
	int			j;

	data = (t_data *)arg;
	current_philo = NULL;
	if (pthread_mutex_lock(&data->lock))
	{
		data->death = 3;
		return (NULL);
	}
	while (data->death == 0)
		check_death(data, &current_philo);
	pthread_mutex_unlock(&data->lock);
	j = 0;
	while (j < data->number_of_philo)
	{
		pthread_join(data->thread[j], NULL);
		j++;
	}
	finish_write(data->death, current_philo, data->max_eat);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_usleep(5);
	philo->time_to_die = get_time() + philo->data->time_to_die \
		- philo->data->start;
	while (philo->data->death == 0)
	{
		if (take_forks(&philo) && philo->data->death == 0)
			philo->data->death = 3;
		if (eat(&philo) && philo->data->death == 0)
			philo->data->death = 3;
		if (philo->id % 2 != 0 && philo->data->death == 0)
			ft_usleep(10);
	}
	return (NULL);
}

int	thread_init(t_data **data)
{
	int			i;

	i = 0;
	if (pthread_mutex_lock(&(*data)->lock))
		return (1);
	if (pthread_create(&(*data)->super, NULL, &super, *data))
		return (1);
	while (i < (*data)->number_of_philo && (*data)->death == 0)
	{
		pthread_create(&(*data)->thread[i], NULL, &routine, \
			&(*data)->philosopher[i]);
		i++;
	}
	pthread_mutex_unlock(&(*data)->lock);
	pthread_join((*data)->super, NULL);
	return (0);
}
