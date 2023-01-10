# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 19:32:42 by broy              #+#    #+#              #
#    Updated: 2022/11/14 11:55:25 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

REMOVE = rm -rf

CC = clang

CFLAGS = -pthread -g -Wall -Werror -Wextra

SOURCES = philo.c \
		  ft_utils.c \
		  ft_launch_sim.c \
		  ft_utils2.c \
		  ft_check_args.c

OBJECTS = $(SOURCES:.c=.o)

all:	$(NAME)

${NAME}:	${OBJECTS}
		${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}
	
clean:
		${REMOVE} ${OBJECTS}

fclean:
		${REMOVE} ${NAME} ${OBJECTS}

re:	fclean all

.PHONY: all clean fclean re
