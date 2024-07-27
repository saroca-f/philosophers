/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:20:47 by saroca-f          #+#    #+#             */
/*   Updated: 2024/07/27 10:02:48 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <inttypes.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\033[37m"
# define GREYM		"\x1B[38;5;245m"
# define GREYM2		"\x1B[38;5;250m"
# define BOLD		"\033[1m"
# define RESET		"\x1b[0m"
# define CLEAR		"\033[2J"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	pthread_t		*thread;
	pthread_t		super;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				death;
	uint64_t		start;
	t_philo			*philosopher;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	lock;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	bool			eating;
	int				eat_times;
	uint64_t		time_to_die;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

//philospher
int			philo_parser(int argc, char **argv, t_data **data);
void		data_init(t_data **data, int argc, char **argv);
int			thread_init(t_data **data);

//philo_utils
long		ft_usleep(int time);
long		get_time(void);

//philo_tools
long int	ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);

//write
void		finish_write(int death, t_philo *current_philo, int max_eat);
int			p_write(t_philo **philo, char *str);

//actions
int			take_forks(t_philo **philo);
int			eat(t_philo **philo);
void		philo_update(t_philo **philo);

//free
void		finish_philo(t_data **data);

#endif
