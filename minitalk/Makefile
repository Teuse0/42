# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 17:08:25 by broy              #+#    #+#              #
#    Updated: 2022/05/18 18:39:25 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
SERVER		= server

SRCS_SERVER		= server.c server_utils.c
SRCS_CLIENT		= client.c client_utils.c
SRCS_SERVER_B	= bonus/server_bonus.c bonus/server_utils_bonus.c
SRCS_CLIENT_B	= bonus/client_bonus.c bonus/client_utils_bonus.c

OBJ_SERVER			= $(SRCS_SERVER:.c=.o)
OBJ_CLIENT			= $(SRCS_CLIENT:.c=.o)
OBJ_SERVER_B		= $(SRCS_SERVER_B:.c=.o)
OBJ_CLIENT_B		= $(SRCS_CLIENT_B:.c=.o)

RM			= rm -rf
CC			= gcc
FLAGS		= -Wall -g -Wextra -Werror

.c.o:	${CC} ${CFLAGS} -c $< o ${<:.c=.o}

all : 		${SERVER} ${CLIENT}

${SERVER}:	$(OBJ_SERVER)
			$(CC) $(OBJ_SERVER) $(FLAGS)  -o $(SERVER)

${CLIENT}: 	$(OBJ_CLIENT)
			$(CC) $(OBJ_CLIENT) $(FLAGS) -o $(CLIENT)

bonus:  $(OBJ_SERVER_B) $(OBJ_CLIENT_B)
		${CC} ${FLAGS} $(OBJ_SERVER_B) -o ${SERVER}
		${CC} ${FLAGS} ${OBJ_CLIENT_B} -o ${CLIENT}

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) ${OBJ_SERVER_B} ${OBJ_CLIENT_B}

fclean:	clean
		$(RM) ${SERVER} ${CLIENT} 

re : 	fclean  all

.PHONY : fclean all re clean
