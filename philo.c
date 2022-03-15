/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:12:35 by smia              #+#    #+#             */
/*   Updated: 2022/03/15 05:35:11 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_philo_status(t_philo *philo, char *s, int lamp)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (s)
		printf("%lld philo %d %s\n", (get_time() - philo->data->time) \
			, philo->index, s);
	if (lamp)
		pthread_mutex_unlock(&philo->data->mutex);
}

void	sets_fork(t_philo *philo, int lamp)
{
	if (lamp)
	{
		pthread_mutex_lock(&philo->data->forks[(philo->index - 1) \
			% philo->data->n_philo]);
		printf_philo_status(philo, "taken a fork", 1);
		pthread_mutex_lock(&philo->data->forks[(philo->index) \
			% philo->data->n_philo]);
		printf_philo_status(philo, "taken a fork", 1);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[(philo->index - 1) \
			% philo->data->n_philo]);
		pthread_mutex_unlock(&philo->data->forks[(philo->index) \
			% philo->data->n_philo]);
	}
}

void	*routine(void *av)
{
	t_philo	*philo;

	philo = av;
	if (!(philo->index & 1))
		ft_usleep(philo->data->t_eat / 2);
	while (1337)
	{
		sets_fork(philo, 1);
		printf_philo_status(philo, "is eating", 1);
		ft_usleep(philo->data->t_eat);
		sets_fork(philo, 0);
		philo->last_eat = get_time();
		printf_philo_status(philo, "is sleeping", 1);
		ft_usleep(philo->data->t_sleep);
		printf_philo_status(philo, "is thinking", 1);
		philo->n_eat += 1;
		if (philo->n_eat >= philo->data->n_eat)
			philo->full_eat = 1;
	}
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->mutex, NULL);
	while (++i < data->n_philo)
		pthread_create(&data->philos[i].th, NULL, routine, &data->philos[i]);
	i = -1;
	while (++i < data->n_philo)
		pthread_detach(data->philos[i].th);
}
