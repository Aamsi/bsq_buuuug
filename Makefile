# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouali <iouali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 09:06:47 by iouali            #+#    #+#              #
#    Updated: 2020/09/30 10:48:59 by iouali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/parsing.c ./srcs/ft_split.c ./srcs/utils.c ./srcs/solution.c ./srcs/solver.c ./srcs/main.c ./srcs/flush.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = bsq
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -I${INCS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re