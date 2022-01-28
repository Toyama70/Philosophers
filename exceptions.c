/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:38:04 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/27 17:41:58 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
int	ft_exit_thread(data *data)
{
	int	n;

	n = 0;
	while (n < data->max)
		if (pthread_detach(data->philo[n++].id))
			return (1);
	return (0);
}

int	ft_free(data *data)
{
	int	n;

	n = 0;
	while (n < data->max)
		if (&data->fork[n])
			if (pthread_mutex_destroy(&data->fork[n++]))
				return (1);
	if (pthread_mutex_destroy(&data->wrtlck))
		return (1);
	free(data->philo);
	free(data->fork);
	return (1);
}

void	ft_exceptions(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	if (atoi(argv[1]) == 0)
		exit(1);

	return;
}
