/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:50:45 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/25 10:54:44 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

typedef struct keys {
	pthread_mutex_t lock;
} keys;
int mails = 0;
pthread_mutex_t lock;

void *myturn(void *args) 
{
	int i = 0;
	pthread_mutex_lock(&lock);
	while (i < 1000000)
		printf("%d\n", i++);
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(int argc, char **argv)
{
	pthread_mutex_init(&lock, NULL);
	int i = 0;
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, &myturn, NULL);
//	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, &myturn, NULL);
//	pthread_join(t2, NULL);
	sleep(3);
	pthread_mutex_destroy(&lock);
}
