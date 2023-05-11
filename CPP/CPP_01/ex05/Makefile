# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 16:22:25 by broy              #+#    #+#              #
#    Updated: 2023/02/13 16:22:26 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp \
			  Harl.cpp
			  
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
CCFLAGS		= -Wall -Wextra -Werror -g -I. -std=c++98

NAME			= Harl

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
