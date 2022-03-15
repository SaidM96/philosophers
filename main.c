/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 03:56:05 by smia              #+#    #+#             */
/*   Updated: 2022/03/15 03:54:37 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->mutex));
	free(data->philos);
	free(data->forks);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) == -1)
		return (1);
	get_args(&data, av, ac);
	if (ft_init(&data) == -1)
		return (1);
	ft_init_philo(&data);
	manager(&data);
	ft_free(&data);
	return (0);
}
