/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:50:15 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/27 17:44:28 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
int	ft_routine(data *data, t_philo *philo)
{
	if (pthread_mutex_lock(&data->fork[philo->rfork]))
		return (1);
	ft_msg(data, philo->nbr, 1);
	if (pthread_mutex_lock(&data->fork[philo->lfork]))
		return (1);
	ft_msg(data, philo->nbr, 1);
	ft_msg(data, philo->nbr, 2);

	philo->limit = ft_gettime() + data->die + 3;
	if (pthread_mutex_lock(&philo->state))
		return (1);
	usleep(data->eat * 1000);
	if (data->status)
		return (1);
	philo->eatcount++;
	return (ft_routine2(data, philo));
}

int	ft_routine2(data *data, t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->state))
		return (1);
	if (pthread_mutex_unlock(&data->fork[philo->lfork]))
		return (1);
	if (pthread_mutex_unlock(&data->fork[philo->rfork]))
		return (1);
	ft_msg(data, philo->nbr, 3);
	usleep(data->slp * 1000);
	if (data->status)
		return (1);
	ft_msg(data, philo->nbr, 4);
	return (0);
}
/*
void	ft_grabfork(data *data, int max, t_philo *philo)
{
		size_t i = philo->nbr;
	//	while(1)
		usleep(600);// i can continue here
		if (philo->nbr != 0 && philo->nbr != max)
		{
			pthread_mutex_lock(&data->fork[i]);
			pthread_mutex_lock(&data->fork[i - 1]);

			ft_msg(data, 2, philo->nbr);
			pthread_mutex_unlock(&data->fork[i]);
			pthread_mutex_unlock(&data->fork[i - 1]);
		}
			

}
*/
/*
int	ft_startthink(data *data, int max, t_philo *philo)
{
	
	
	ft_msg(data, 1, philo->nbr);
	if (philo->nbr % 2 == 0)
		ft_routine(data, philo);
	else
	{
		usleep(60);
		ft_routine(data, philo);
	}

	return 0;
}*/
