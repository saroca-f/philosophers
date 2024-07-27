/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:46:21 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/25 19:59:24 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	p_write(t_philo **philo, char *str)
{
	long unsigned int	time;

	if (pthread_mutex_lock(&(*philo)->data->write))
		return (1);
	time = get_time() - (*philo)->data->start;
	printf(MAGENTA"%lu"RESET" %d %s\n", time, (*philo)->id, str);
	pthread_mutex_unlock(&(*philo)->data->write);
	return (0);
}

void	finish_write(int death, t_philo *philo, int max_eat)
{
	if (death == 1)
	{
		if (p_write(&philo, RED"died"RESET))
		{
			death = 3;
			philo->data->death = 3;
		}
	}
	if (death == 2)
		printf(GREEN"Everyone has eaten %d times\n"RESET, max_eat);
	if (death == 3)
		printf("ERROR:"RED"One lock goes wrong\n"RESET);
}
