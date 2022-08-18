# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 14:09:18 by broy              #+#    #+#              #
#    Updated: 2022/07/01 02:02:26 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

REMOVE	= rm -rf

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIBFT = libft/libft.a
LIBFT_PATH = libft

SOURCES	= 	push_swap.c \
			ft_actions.c \
			ft_check_args.c \
			ft_check_args_2.c \
			ft_exit.c \
			ft_ps_lst.c \
			ft_input.c \
			ft_quick_sort.c \
			ft_itob.c \
			ft_push.c

OBJECTS	=	$(SOURCES:.c=.o)

all:	$(NAME)

${LIBFT}:
		make bonus -C ${LIBFT_PATH}

${NAME}:	${OBJECTS} ${LIBFT}
		${CC} ${CFLAGS} ${OBJECTS} -o ${NAME} ${LIBFT}

clean:
		make clean -C ${LIBFT_PATH}
		${REMOVE} ${OBJECTS}

fclean:
		make fclean -C ${LIBFT_PATH}
		${REMOVE} ${NAME} ${OBJECTS}

re:	fclean all

.PHONY:	all clean fclean re 
