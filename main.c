/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:18:52 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/25 20:09:51 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosopher.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (philo_parser(argc, argv, &data) == 1)
		return (1);
	if (argc >= 6 && (ft_atoi(argv[5]) == 0))
	{
		printf(GREEN"Everyone has eaten 0 times\n"RESET);
		free(data);
		return (0);
	}
	else
	{
		data_init(&data, argc, argv);
		thread_init(&data);
	}
	finish_philo(&data);
	return (0);
}
