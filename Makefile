# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 11:04:37 by melkhatr          #+#    #+#              #
#    Updated: 2025/07/28 12:13:50 by melkhatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = algo.c check_error.c ft_split.c \
       operation.c operation2.c operation3.c operation4.c \
       position.c push_swap.c stack.c \
       utils1.c utils2.c utils4.c


CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${SRCS} -o ${NAME}

clean:
	@${RM} ${OBJS}
 
fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
