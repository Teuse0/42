# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 16:30:54 by broy              #+#    #+#              #
#    Updated: 2022/04/18 15:04:12 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c ft_printf_utils.c ft_print_adress.c ft_print_uint.c\
			  ft_print_hex.c ft_utils/ft_itoa.c ft_utils/ft_putstr_fd.c\
			  ft_utils/ft_putchar_fd.c

OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:		
			rm -f ${OBJS}
			rm -f ft_utils/*.o


fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
