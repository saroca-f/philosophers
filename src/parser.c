/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:47:48 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/25 18:18:58 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

bool	check_time_args(int argc, char **argv)
{
	int	flag;

	flag = true;
	if (argc >= 2 && ft_atoi(argv[1]) < 1)
	{
		printf(RED"Error:"RESET" No Philosophers\n");
		flag = false;
	}
	if (argc >= 3 && ft_atoi(argv[2]) < 1)
	{
		printf(RED"Error:"RESET" Die time must be a number greater than 0\n");
		flag = false;
	}
	if (argc >= 4 && ft_atoi(argv[3]) < 1)
	{
		printf(RED"Error:"RESET" Eat time must be a number greater than 0\n");
		flag = false;
	}
	if (argc >= 5 && ft_atoi(argv[4]) < 1)
	{
		printf(RED"Error:"RESET" Sleep time must be a number greater than 0\n");
		flag = false;
	}
	return (flag);
}

bool	check_args(int argc, char **argv)
{
	int	flag;

	flag = true;
	if (argc < 5)
	{
		printf(RED"Error:"RESET" An additional ");
		printf("\033[1m%d\033[0m arguments are required.\n", 5 - argc);
		flag = false;
	}
	if (argc > 6)
	{
		printf(RED"Error:"RESET" There are");
		printf(" \033[1m%d\033[0m excess arguments.\n", argc - 6);
		flag = false;
	}
	if (check_time_args(argc, argv) == false)
		flag = false;
	if (argc >= 6 && (ft_atoi(argv[5]) < 0))
	{
		printf(RED"Error:"RESET" Number of times each ");
		printf("philosopher must eat must be 0 or more\n");
		flag = false;
	}
	return (flag);
}

int	philo_parser(int argc, char **argv, t_data **data)
{
	if (!check_args(argc, argv))
	{
		free(*data);
		return (1);
	}
	return (0);
}
