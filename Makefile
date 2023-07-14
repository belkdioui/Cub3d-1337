# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:48:27 by rrhnizar          #+#    #+#              #
#    Updated: 2023/07/14 19:27:31 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = ./inc/libft/libft.a

SRCM = test.c main.c initialization.c \
	src/cub3D.c inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c src/verifaction_and_return_map.c src/utils1_cub3D.c src/check_the_map.c\
		src/check_is_element_and_return_it.c src/check_is_element_and_return_it-1.c src/check_the_map-1.c src/check_space_is_protected.c

RFLAG = -Wall -Werror -Wextra

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

CC = cc ${RFLAG}

OBJM = ${SRCM:.c=.o}

%.o : %.c
	${CC} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJM}
	@make -C ./inc/libft/
	${CC} ${MLXFLAG} ${OBJM} ${LIBFT} -o ${NAME}

clean : 
	rm -rf ${OBJM}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re

	