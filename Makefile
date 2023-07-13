# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:48:27 by rrhnizar          #+#    #+#              #
#    Updated: 2023/07/13 16:35:15 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCM = main.c initialization.c

RFLAG = -Wall -Werror -Wextra

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

CC = cc ${RFLAG}

OBJM = ${SRCM:.c=.o}

%.o : %.c
	${CC} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJM}
	${CC} ${MLXFLAG} ${OBJM} -o ${NAME}

clean : 
	rm -rf ${OBJM}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re

	