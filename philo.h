/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:52:24 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/02 12:03:07 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philo {
	pthread_mutex_t	state;
	pthread_t		id;
	uint64_t		limit;
	uint64_t		last_eat;
	int				eatcount;
	int				status;
	int				rfork;
	int				lfork;
	int				nbr;
	int				n;
}	t_philo;

typedef struct data {
	pthread_mutex_t	*fork;
	pthread_mutex_t	log;
	pthread_t		thread;
	pthread_t		m_thread;
	pthread_t		mc_thread;
	t_philo			*philo;
	uint64_t		start;
	uint64_t		ttd;
	uint64_t		tte;
	uint64_t		tts;
	int				eatcount;
	int				max;
	int				status;
	int				n;
	int				argc;
}	t_data;

void		*ft_start(void *smths);
void		ft_msg(t_data *data, int nbr, int msg);
int			ft_init(int argc, char *argv[], t_data *data);
int			ft_philo_init(t_data *data, int n);
int			ft_exit_thread(t_data *data);
int			ft_fork_init(t_data *data);

int			ft_routine(t_data *data, t_philo *philo);
int			ft_routine2(t_data *data, t_philo *philo);

uint64_t	ft_gettime(void);
void		ft_putnbr(uint64_t n);
int			ft_isnum(char *str);
int			ft_atoi(char *str);

void		*ft_monitor_count(void *param);
void		*ft_monitor(void *param);
void		ft_monitoring(t_data *data, int n, int j);
int			ft_exceptions(int argc, char *argv[], t_data *data);
int			ft_checkeat(t_data *data, int nbr);
int			ft_free(t_data *data);
int			ft_error(int nbr);
int			ft_onlynum(int argc, char **argv);

#endif
