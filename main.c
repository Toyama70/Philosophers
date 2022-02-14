/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:28:21 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/02 11:57:39 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		n;
	int		j;

	n = 0;
	j = 0;
	if (ft_exceptions(argc, argv, &data) == -1)
		return (1);
	if (ft_onlynum(argc, argv) == 1)
		return (1);
	if (ft_init(argc, argv, &data) == 1)
		return (ft_free(&data));
	ft_monitoring(&data, n, j);
	if (ft_exit_thread(&data))
		return (ft_free(&data));
	usleep(150);
	ft_free(&data);
	return (0);
}

void	*ft_start(void *param)
{
	t_data	*data;
	t_philo	*philo;

	data = param;
	philo = &data->philo[data->n];
	philo->limit = ft_gettime() + data->ttd;
	philo->eatcount = 0;
	if (pthread_mutex_init(&philo->state, NULL))
		return ((void *) 1);
	while (!data->status)
	{
		if (ft_routine(data, philo) == 1)
		{
			data->status = -1;
			break ;
		}
	}
	pthread_mutex_destroy(&philo->state);
	return ((void *) 0);
}

int	ft_init(int argc, char *argv[], t_data *data)
{
	data->max = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	data->n = 0;
	if (argc == 6)
		data->eatcount = ft_atoi(argv[5]);
	else
		data->eatcount = -1;
	data->philo = malloc(sizeof(t_philo) * data->max);
	if (!data->philo)
		return (1);
	if (pthread_mutex_init(&data->log, NULL))
		return (ft_free(data));
	if (ft_fork_init(data) == 1)
		return (1);
	while (data->n < data->max)
	{
		if (ft_philo_init(data, data->n) == 1)
			return (1);
		data->n++;
	}
	return (0);
}

int	ft_fork_init(t_data *data)
{
	int	n;

	n = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->max);
	if (!data->fork)
		return (1);
	while (n < data->max)
	{
		if (pthread_mutex_init(&data->fork[n], NULL))
			return (1);
		data->philo[n].rfork = n;
		if (n == data->max - 1)
			data->philo[n].lfork = 0;
		else
			data->philo[n].lfork = n + 1;
		n++;
	}
	return (0);
}

int	ft_philo_init(t_data *data, int n)
{
	data->philo[n].nbr = n + 1;
	data->philo[n].status = 0;
	data->philo[n].n = n;
	if (pthread_create(&data->philo[data->n].id, NULL, ft_start, data))
		return (1);
	usleep(150);
	return (0);
}
