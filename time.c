/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:32:42 by smia              #+#    #+#             */
/*   Updated: 2022/03/15 05:36:46 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	x;

	gettimeofday(&x, NULL);
	return ((x.tv_sec * 1e3) + (x.tv_usec / 1e3));
}

void	ft_usleep(unsigned long time)
{
	unsigned long	curr;

	curr = get_time();
	while (get_time() - curr < time)
		usleep(50);
}

int	ft_atoi(char *str)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + str[i] - 48;
			i++;
		}
		else
			return (-1);
	}
	if (n > 2147483647)
		return (-1);
	return (n);
}
