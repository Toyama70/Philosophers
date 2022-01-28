/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:36:00 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/27 17:40:59 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct	philo {
	pthread_t		id;
	pthread_mutex_t	state;
	size_t			nbr; //n+1
	size_t			nb;
	int				sts;
	uint64_t		limit;
	int 			lfork;
	int 			rfork;
	int				eatcount;
} t_philo;

typedef struct	data {
	int				nb;
	uint64_t		eat; //status 2
	uint64_t		die; //status 1
	uint64_t		slp; //status 3
	int				must;
	int				max;
	int				eatcount;
	size_t			counter;
	pthread_mutex_t	wrtlck;
	pthread_mutex_t	idset;
	pthread_mutex_t	*fork;
	int				status;
	uint64_t		start;
	t_philo 		*philo;
} data;

//void		ft_setdata(int argc, char **argv);
void		ft_exceptions(int argc, char **argv);
uint64_t	ft_gettime(void);
void		ft_msg(data *data, size_t id,int msg);
void		ft_putchar(char c);
void		ft_putnbr(uint64_t n);
int		ft_startthink(data *data, int max, t_philo *philo);
void		ft_grabfork(data *data, int max, t_philo *philo);
void	ft_fork_init(data *data);
void		ft_statusmonitor(data *data, int a, int b);
int	ft_routine2(data *data, t_philo *philo);
int	ft_free(data *data);
int	ft_exit_thread(data *data);
int	ft_routine(data *data, t_philo *philo);

#endif
