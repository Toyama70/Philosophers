/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:36:30 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/25 14:50:27 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_initmutex(pthread_mutex_t *spoon,int max)
{
	int i = 0;

	while(i < max)
	{
		pthread_mutex_init(&spoon[i], NULL);
		printf("init %d\n", i);
		i++;
	}
}

void	ft_eat(philo **philo, pthread_mutex_t *spoon, data data)
{
	int i = 0;
	
	pthread_mutex_lock(&spoon[0]);
	while(i < 1000000)
		i++;
		//printf("working %d\n", i++);
	pthread_mutex_unlock(&spoon[0]);

}

void *ft_routine(void *philo1)
{
	philo* philo2 = philo1;
	printf("philo stats = %d\n", philo2[0].sts);
	
	return NULL;
}

void	ft_createthreads(pthread_t *thread, int max, philo *philo)
{
	int	i = 0;

	while (i < max)
	{
		pthread_create(&thread[i], NULL, &ft_routine, philo);
		i++;
	}
}

void	ft_setdata(int argc, char **argv)
{
	data data;
	pthread_mutex_t *spoon;
	pthread_t *thread;
	philo *philo;

	data.max = atoi(argv[1]); 	
	ft_exceptions(argc, argv);
	philo = malloc(sizeof(philo) * data.max);
	spoon = malloc(sizeof(pthread_mutex_t) * data.max); 
	thread = malloc(sizeof(pthread_t) * data.max);
	ft_initmutex(spoon, data.max);
	ft_eat(&philo, spoon, data);
	philo[0].sts = 3;
	ft_createthreads(thread, data.max, philo);
}
