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

NAME	= cub3D

REMOVE = rm -rf

LFLAGS = -L mlx_linux -lXext -lX11 -L libft -lft -lm
MLX 	= minilibx-linux/libmlx.a
MLX_2	= minilibx-linux/libmlx_Linux.a
MLX_PATH = minilibx-linux

CC = clang

CFLAGS = -g -Wall -Werror -Wextra -Ofast

SOURCES = 	cub3d.c \
		parsing/parse_map.c \
		parsing/parse_infos.c \
		ft_free.c \
		launch.c \
		minimap.c \
		init/init.c \
		init/init_colors.c \
		init/init_textures.c \
		raycasting.c \
		check_chars.c

OBJECTS = $(SOURCES:.c=.o)

all:	$(NAME)

${MLX}:
		make -C ${MLX_PATH}

${NAME}:	${OBJECTS} ${MLX}
		make -C libft
		${CC} ${CFLAGS} ${OBJECTS} -o ${NAME} ${MLX} ${MLX_2} ${LFLAGS} -I libft/libft.a
	
clean:
		${REMOVE} ${OBJECTS}
		make clean -C ${MLX_PATH}
		make clean -C libft

fclean:
		${REMOVE} ${NAME} ${OBJECTS}
		make clean -C ${MLX_PATH}
		make fclean -C libft
		
re:	fclean all

.PHONY: all clean fclean re
