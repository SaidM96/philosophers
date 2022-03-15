/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 03:55:57 by smia              #+#    #+#             */
/*   Updated: 2022/03/15 05:36:11 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		th;
	long long		last_eat;
	int				index;
	int				n_eat;
	int				full_eat;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int					die;
	long long			time;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_eat;
	pthread_mutex_t		mutex;
	pthread_mutex_t		mtx_die;
	t_philo				*philos;
	pthread_mutex_t		*forks;
}	t_data;

int			check_args(int ac, char **av);
void		get_args(t_data *data, char **av, int ac);
int			ft_atoi(char *str);
int			ft_init(t_data *data);
long long	get_time(void);
void		ft_usleep(unsigned long time);
void		*manager(t_data *data);
void		printf_philo_status(t_philo *philo, char *s, int lamp);
void		ft_init_philo(t_data *data);
void		*routine(void *av);
void		sets_fork(t_philo *philo, int lamp);
void		printf_philo_die(t_philo *philo);

#endif