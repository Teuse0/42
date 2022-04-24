# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnaud <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 09:48:44 by vnaud             #+#    #+#              #
#    Updated: 2022/03/06 17:05:03 by vnaud            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02
SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
CC		= gcc

all:		${NAME}
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
