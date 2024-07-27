/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:39:28 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/25 20:13:31 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	end_mutex(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->number_of_philo)
	{
		pthread_mutex_destroy(&(*data)->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&(*data)->lock);
	pthread_mutex_destroy(&(*data)->write);
	free((*data)->forks);
}

void	finish_philo(t_data **data)
{
	end_mutex(data);
	free((*data)->thread);
	free((*data)->philosopher);
	free(*data);
}
