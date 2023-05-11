# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 16:20:28 by broy              #+#    #+#              #
#    Updated: 2023/03/01 16:20:29 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp \
			  FragTrap.cpp
			  
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
CCFLAGS		= -Wall -Wextra -Werror -g -I. -std=c++98

NAME			= FragTrap

%.o	: %.cpp
	$(CC) $(CCFLAGS) -c $< -o ${<:.cpp=.o}

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
