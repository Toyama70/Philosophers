# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 12:13:02 by ybestrio          #+#    #+#              #
#    Updated: 2022/02/13 10:53:47 by ybestrio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME1 = Philo 

SRCS1 = exceptions.c main.c routine.c utils.c

OBJS1 = $(SRCS1:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1)  -o $(NAME1)


all:	$(NAME1)

clean:
		$(RM) $(OBJS1)

fclean:	clean
		$(RM) $(NAME1)

re:		fclean all

.PHONY: all clean fclean re

