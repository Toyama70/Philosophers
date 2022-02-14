/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:48:26 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/02 11:07:40 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_routine(t_data *data, t_philo *philo)
{
	if (pthread_mutex_lock(&data->fork[philo->rfork]))
		return (1);
	ft_msg(data, philo->nbr, 1);
	if (pthread_mutex_lock(&data->fork[philo->lfork]))
		return (1);
	ft_msg(data, philo->nbr, 1);
	ft_msg(data, philo->nbr, 2);
	philo->limit = ft_gettime() + data->ttd + 3;
	if (pthread_mutex_lock(&philo->state))
		return (1);
	usleep(data->tte * 1000);
	if (data->status)
		return (1);
	philo->eatcount++;
	return (ft_routine2(data, philo));
}

int	ft_routine2(t_data *data, t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->state))
		return (1);
	if (pthread_mutex_unlock(&data->fork[philo->lfork]))
		return (1);
	if (pthread_mutex_unlock(&data->fork[philo->rfork]))
		return (1);
	ft_msg(data, philo->nbr, 3);
	usleep(data->tts * 1000);
	if (data->status)
		return (1);
	ft_msg(data, philo->nbr, 4);
	return (0);
}

void	ft_everyone_ate(t_data *data, int n)
{
	ft_msg(data, n, 5);
	data->status = -1;
	usleep(300);
	write(1, "Everyone has eaten\n", 19);
	return ;
}

void	ft_monitoring(t_data *data, int n, int j)
{
	while (!data->status)
	{
		n = 0;
		j = 0;
		while (!data->status && n < data->max)
		{
			if (ft_gettime() >= data->philo[n].limit)
			{
				ft_msg(data, n + 1, -1);
				data->status = -1;
				pthread_mutex_lock(&data->philo[n].state);
				return ;
			}
			if (ft_checkeat(data, n) != 0)
				j++;
			n++;
		}
		if (j == data->max)
		{
			ft_everyone_ate(data, n);
			return ;
		}
	}
}

void	ft_msg(t_data *data, int nbr, int msg)
{
	if (!data || data->status || msg == 5)
		return ;
	pthread_mutex_lock(&data->log);
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
		pthread_mutex_unlock(&data->log);
}
