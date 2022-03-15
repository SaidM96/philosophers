/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:17:00 by smia              #+#    #+#             */
/*   Updated: 2022/03/15 05:34:54 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_n_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->philos[i].full_eat == 0)
			return (0);
		i++;
	}
	return (1);
}

void	*manager(t_data *data)
{
	int	i;

	i = 0;
	while (1337)
	{
		if (i == data->n_philo)
			i = 0;
		if (data->n_eat != -1)
			if (check_n_eat(data))
				return (NULL);
		if ((get_time() - data->philos[i].last_eat) >= data->t_die)
		{
			printf_philo_status(&data->philos[i], "died", 0);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}
