/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:35:00 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/27 17:42:08 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_fork_init(data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->max);
/*	if (!data->fork)
		return (1);
*/	while (i < data->max)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		data->philo[i].rfork = i;
		if (i == data->max - 1)
			data->philo[i].lfork = 0;
		else
			data->philo[i].lfork = i + 1;
		i++;
	}

}

/*int main(int argc, char **argv)
{

	ft_exceptions(argc, argv);
	ft_setdata(argc, argv);
	usleep(1);





}*/
