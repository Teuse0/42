MAKEFLAGS += -sj

SRCS = ft_isalpha.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_atol.c \
		ft_strlcat.c \
		ft_strcat.c \
		ft_strncmp.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_power.c \
		ft_fprintf/ft_fprintf.c \
		ft_fprintf/ft_fprintf_utils.c \
		ft_fprintf/ft_fprintf_utils2.c \
		ft_split_len.c \
		ft_split_size.c \
		ft_split_append.c \
		ft_getenv.c \
		ft_split_dup.c \
		ft_split_quotes.c \
		ft_split_free.c \
		ft_split_join.c \
		ft_split_remove.c \
		ft_split_sort.c \
		ft_strrem.c \
		ft_split_slice.c \
		ft_split_count.c \
		ft_strcount.c \
		ft_split_print.c

NORMAL := ${shell tput sgr0}
RED := ${shell tput setaf 1}
GREEN := ${shell tput setaf 2}
BLUE := ${shell tput setaf 4}

OBJS	= ${SRCS:.c=.o}
NAME	:= libft.a
CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror -g3

STEP	:= 0

.c.o:
			@printf "\033[1K"
			@printf "\r$(RED)[ $(GREEN)libft$(RED) %d%% ]$(NORMAL)" $$(( $(STEP) * 100 / ($(words $(SRCS)) - 1) ))
			@${CC} -c ${CFLAGS} $< -o ${<:.c=.o}
			@$(eval STEP=$(shell echo $$(($(STEP)+1))))

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@if [ $(MAKELEVEL) -eq 1 ]; then \
				printf "\033[1K"; \
				printf "\r$(RED)Compiled$(NORMAL)\n"; \
			fi

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean
			@${MAKE} all

all:		${NAME}

.PHONY: clean, fclean, re, all
