/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:22:35 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/27 17:28:20 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_checkeat(data *data, int nbr)
{
	if (data->eatcount == -1)
		return (0);
	if (data->philo[nbr].eatcount >= data->eatcount)
		return (1);
	return (0);
}

void	ft_statusmonitor(data *data, int a, int b)
{
	while (!data->status)
	{
		a = 0;
		b = 0;
		while (!data->status && a < data->max)
		{
			if (ft_gettime() >= data->philo[a].limit)
			{
				ft_msg(data, -1, a + 1);
				data->status = -1;
				pthread_mutex_lock(&data->philo[a].state);
				return ;
			}
			if (ft_checkeat(data, a))
				b++;
			a++;
		}
		if (b == data->max)
		{
			ft_msg(data, 5, a);
			data->status = -1;
			pthread_mutex_lock(&data->philo[a].state);
			return ;
		}
	}
}

void ft_msg(data *data, size_t nbr, int msg)
{
/*	pthread_mutex_lock(&data->wrtlck);
	ft_putnbr(ft_gettime() - data->start);
	write(1, " ", 1);
	ft_putnbr(id);
	if (msg == 1)
	{
		write(1, " is thinking\n", 13);
	}
	if (msg == 2)
	{
		write(1, " took a fork\n", 13 );
	}
	usleep(5000);
	pthread_mutex_unlock(&data->wrtlck);*/
	if (!data || data->status || msg == 5)
		return ;
	pthread_mutex_lock(&data->wrtlck);
	if (data->status)
		return ;
	ft_putnbr(ft_gettime() - data->start);
	write (1, " ", 1);
	ft_putnbr(nbr);
	if (msg == -1)
		write(1, " died\n", 6);
	else if (msg == 1)
		write(1, " has taken a fork\n", 19);
	else if (msg == 2)
		write(1, " is eating\n", 12);
	else if (msg == 3)
		write(1, " is sleeping\n", 14);
	else if (msg == 4)
		write(1, " is thinking\n", 14);
	if (!data->status)
		pthread_mutex_unlock(&data->wrtlck);
}

uint64_t	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (uint64_t)1000 + (time.tv_usec / 1000));
}
