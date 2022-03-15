/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:11:18 by smia              #+#    #+#             */
/*   Updated: 2022/03/15 05:33:59 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("invalide arguments !\n");
		return (0);
	}
	ac = 1;
	while (av[ac])
	{
		if (ft_atoi(av[ac]) <= 0)
		{
			printf("invalide arguments !\n");
			return (0);
		}
		ac++;
	}
	return (1);
}

void	get_args(t_data *data, char **av, int ac)
{
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
	else
		data->n_eat = -1;
	data->t_sleep = ft_atoi(av[4]);
}

int	ft_init(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * (data->n_philo));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->philos || !data->forks)
		return (printf("malloc error !\n"), -1);
	data->time = get_time();
	while (++i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (printf("mutex init error !\n"), -1);
		data->philos[i].index = i + 1;
		data->philos[i].n_eat = 0;
		data->philos[i].data = data;
		data->philos[i].last_eat = data->time;
		data->philos[i].full_eat = 0;
	}
	return (1);
}
