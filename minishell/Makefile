MAKEFLAGS += -sj

SRCS :=		exec_cmd/exec_cmd.c \
			exec_cmd/utils.c \
			exec_cmd/utils2.c \
			exec_cmd/error.c \
			exec_cmd/exec.c \
			exec_cmd/exec2.c \
			exec_cmd/exec3.c \
			exec_cmd/here_doc.c \
			builtins/echo.c \
			builtins/cd.c \
			builtins/pwd.c \
			builtins/export.c \
			builtins/unset.c \
			builtins/env.c \
			builtins/exit.c \
			parsing/cmd.c \
			parsing/parsing.c \
			parsing/parsing2.c \
			parsing/parsing3.c \
			parsing/parsing_utils.c \
			parsing/parsing_utils_2.c \
			parsing/pars_env.c \
			parsing/ft_size_malloc_env.c \
			parsing/pars_env_utils.c \
			parsing/pars_env_utils_2.c \
			parsing/check_cmd.c \
			parsing/check_cmd_utils.c \
			parsing/sep.c \
			parsing/normalize.c \
			parsing/lst_to_cmd.c \
			parsing/lst_to_cmd2.c \
			parsing/lst_to_cmd3.c \
			parsing/lst_to_cmd4.c \
			parsing/lst_to_cmd5.c \
			parsing/lst_to_cmd_utils.c \
			parsing/lst_to_cmd_utils_2.c \
			utils.c \
			utils2.c \
			minishell2.c \
			minishell.c
FT_SRC :=	./libft

NORMAL		:= ${shell tput sgr0}
RED			:= ${shell tput setaf 1}
GREEN		:= ${shell tput setaf 2}
BLUE		:= ${shell tput setaf 4}

OBJS	:=	${SRCS:.c=.o}
NAME	:=	minishell
CC		:=	clang
CFLAGS	:=	-Wall -Wextra -Werror -g3
LIBS	:=	-lft -L${FT_SRC} -lreadline

STEP	:= 0

.c.o:
			@printf "\033[1K"
			@printf "\r$(RED)[ $(BLUE)minishell$(RED) %d%%]$(NORMAL)" $$(( $(STEP) * 100 / ($(words $(SRCS)) - 1) ))
			@${CC} -c ${CFLAGS} $< -o ${<:.c=.o}
			@$(eval STEP=$(shell echo $$(($(STEP)+1))))

${NAME}:	${OBJS}
			@make -sC ${FT_SRC}
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}
			@if [ $(MAKELEVEL) -eq 1 ]; then \
				printf "\033[1K"; \
				printf "\r$(RED)Compiled$(NORMAL)\n"; \
			fi

clean:
			@make -sC ${FT_SRC} clean
			@${RM} ${OBJS}

fclean:
			@make -sC ${FT_SRC} fclean
			@${RM} ${OBJS} ${NAME}

re:			fclean
			@${MAKE} all

all:		${NAME}

.PHONY: clean, fclean, re, all
