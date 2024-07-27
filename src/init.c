/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:51:45 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/24 19:39:48 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	philo_init(t_philo **philosopher, t_data **data)
{
	int	i;

	i = 0;
	(*philosopher) = ft_calloc((*data)->number_of_philo, sizeof(t_philo));
	if (!(*philosopher))
		return ;
	while (i < (*data)->number_of_philo)
	{
		(*philosopher)[i].data = (*data);
		(*philosopher)[i].id = i + 1;
		(*philosopher)[i].l_fork = &(*data)->forks[i];
		(*philosopher)[i].eat_times = 0;
		(*philosopher)[i].time_to_die = (*data)->time_to_die;
		if (i + 1 == (*data)->number_of_philo)
			(*philosopher)[i].r_fork = &(*data)->forks[0];
		else
			(*philosopher)[i].r_fork = &(*data)->forks[i + 1];
		i++;
	}
}

void	forks_init(pthread_mutex_t **forks, int size)
{
	int	i;

	i = 0;
	(*forks) = malloc(sizeof(pthread_mutex_t) * (40 * size));
	if (!(*forks))
		return ;
	while (i < size)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
}

void	mutex_init(t_data *data)
{
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
}

void	data_init(t_data **data, int argc, char **argv)
{
	(*data)->number_of_philo = ft_atoi(argv[1]);
	(*data)->time_to_die = ft_atoi(argv[2]);
	(*data)->time_to_eat = ft_atoi(argv[3]);
	(*data)->time_to_sleep = ft_atoi(argv[4]);
	(*data)->death = 0;
	(*data)->start = get_time();
	(*data)->max_eat = 0;
	if (argc == 6)
		(*data)->max_eat = ft_atoi(argv[5]);
	(*data)->thread = malloc(sizeof(pthread_t) * (*data)->number_of_philo);
	if (!(*data)->thread)
		return ;
	mutex_init(*data);
	forks_init(&(*data)->forks, (*data)->number_of_philo);
	if (!(*data)->forks)
		return ;
	philo_init(&(*data)->philosopher, data);
	if (!(*data)->philosopher)
		return ;
}
