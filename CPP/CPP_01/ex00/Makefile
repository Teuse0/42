# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 17:23:52 by broy              #+#    #+#              #
#    Updated: 2023/02/11 17:23:56 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= Zombie.cpp \
			  main.cpp \
			  newZombie.cpp \
			  randomChump.cpp
			  
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
CCFLAGS		= -Wall -Wextra -Werror -g -I. -std=c++98

NAME			= Zombie

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
