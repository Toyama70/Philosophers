/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:36:31 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/02 11:44:32 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_exceptions(int argc, char **argv, t_data *data)
{
	int	n;

	n = 2;
	if (argc < 5 || argc > 6)
	{
		write(1, "Argument error\n", 15);
		return (-1);
	}
	while (n < argc - 1)
	{
		if (ft_atoi(argv[n]) < 60 || ft_atoi(argv[1]) < 1 || (argc == 6
				&& ft_atoi(argv[5]) < 0))
		{
			write(1, "Argument error\n", 15);
			return (-1);
		}
		n++;
	}
	if (argc == 7 && ft_atoi(argv[6]) == 0)
		return (-1);
	data->start = ft_gettime();
	data->status = 0;
	data->argc = argc;
	return (1);
}

int	ft_free(t_data *data)
{
	int	n;

	n = 0;
	while (n < data->max)
		if (&data->fork[n])
			if (pthread_mutex_destroy(&data->fork[n++]))
				return (1);
	if (pthread_mutex_destroy(&data->log))
		return (1);
	free(data->philo);
	free(data->fork);
	return (1);
}

int	ft_error(int nbr)
{
	if (nbr == 1)
		write(1, "thread error\n", 13);
	return (nbr);
}

int	ft_checkeat(t_data *data, int nbr)
{
	if (data->eatcount == -1)
		return (0);
	if (data->philo[nbr].eatcount >= data->eatcount)
		return (1);
	return (0);
}

int	ft_exit_thread(t_data *data)
{
	int	n;

	n = 0;
	while (n < data->max)
		if (pthread_detach(data->philo[n++].id))
			return (1);
	return (0);
}
