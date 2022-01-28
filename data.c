/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:36:30 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/27 17:43:40 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_initmutex(data *data,int max)
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

void *ft_setter(void *data1)
{
	data* data2 = data1; //thats the trick
	t_philo *philo = &data2->philo[data2->nb];

	philo->limit = ft_gettime() + data2->die;
	philo->eatcount = 0;
	if (pthread_mutex_init(&philo->state, NULL))
		return ((void *) 1);
	while (!data2->status)// double check this condition
	{
		if (ft_routine(data2, philo) == 1)
		{
			data2->status = -1;
			break ;
		}
	}

//	ft_startthink(data2, data2->max, philo);//=> problem is her
	pthread_mutex_destroy(&philo->state);
	return ((void *) 0);
}

void	ft_philo_init(data *data, int nb)
{
	data->philo[nb].nbr = nb+1;
	data->philo[nb].sts = 0;
	data->philo[nb].nb = nb;
	pthread_create(&data->philo[data->nb].id, NULL, &ft_setter, data);

	usleep(150);//desserrer les timings selon la puissance de la machine

}

void	ft_datastart(int max, data *data)
{
	int	i;
   
	i = 0;
	data->nb = 0;
	data->status = 0;
	data->start = ft_gettime();
	ft_fork_init(data);
	while (data->nb < data->max)
	{
		ft_philo_init(data, data->nb);
		data->nb++;
	}
}

void ft_initmtx(data *data)
{
	pthread_mutex_init(&data->wrtlck, NULL);
	pthread_mutex_init(&data->idset, NULL);
}

int	main(int argc, char **argv)
{
	data	data;
	int		a;
	int		b;

	ft_exceptions(argc, argv);
	a = 0;
	b = 0;
	data.max = atoi(argv[1]);
	data.die = atoi(argv[2]);
	data.eat = atoi(argv[3]);
	data.slp = atoi(argv[4]);
	data.eatcount = -1;

	ft_exceptions(argc, argv);
	data.philo = malloc(sizeof(data.philo) * data.max);
	data.fork = malloc(sizeof(pthread_mutex_t) * data.max); 
	ft_initmutex(&data, data.max);
	data.counter = (size_t)malloc(sizeof(size_t));
	data.counter = -1;
	data.status = 0;
	ft_initmtx(&data);
	ft_datastart(data.max, &data);
	while (data.status == 0)
		ft_statusmonitor(&data, a, b);
	if (ft_exit_thread(&data))
		return (ft_free(&data));
	//ft_free(&data);
	//usleep(15000);
}
