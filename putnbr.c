/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:14:19 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/26 18:11:57 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(uint64_t n)
{
	unsigned int	nbr;

	nbr = (unsigned int) n;
	while (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr %= 10;
	}
	nbr += '0';
	write(1, &nbr, 1);
}
