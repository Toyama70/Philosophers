/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:50:45 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/19 14:12:22 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *myturn(void *arg) 
{
	while (1)
	{
		sleep(1);
		printf("Ouhoooo\n");
	}
	return (NULL);
}

void yourturn()
{
	while(1)
	{
		sleep(2);
		printf("Pause\n");



	}




}

int main(int argc, char **argv)
{
	pthread_t newthread;
	
	pthread_create(&newthread, NULL, myturn, NULL);
	//myturn();
	yourturn();


}
