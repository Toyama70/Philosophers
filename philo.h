/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:36:00 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/25 13:04:04 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	data {
	int	nb;
	int	die; //status 0
	int	eat; //status 2
	int thk; //status 1
	int	slp; //status 3
	int must;
	int max;
} data;

typedef struct	philo {
	int	id;
	int	sts; //start at 1
} philo;

void	ft_setdata(int argc, char **argv);
void	ft_exceptions(int argc, char **argv);


#endif
