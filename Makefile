# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahour <achahour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 17:05:13 by achahour          #+#    #+#              #
#    Updated: 2025/06/03 23:45:42 by achahour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= pipex
PROG_B  = pipex_bonus

SRCS 	= pipex.c utils.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= pipex.c

SRCS_B	= srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= pipex_bonus.c

HEADER	= -Iincludes

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -g

%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@$(CC) ${OBJS} -Llibft -lft -o ${PROG}
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"


bonus:		${PROG_B}

${PROG_B}:	${OBJS_B}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@$(CC) ${OBJS_B} -Llibft -lft -o ${PROG_B}
					@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

re_bonus:	fclean bonus

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re re_bonus bonus party