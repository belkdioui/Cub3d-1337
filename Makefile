# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:48:27 by rrhnizar          #+#    #+#              #
#    Updated: 2023/07/15 14:46:17 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = ./inc/libft/libft.a

SRCM = main.c initialization.c mlx_utils.c drawing_map_utils.c \
		srcs/check_map/cub3D.c inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c \
		srcs/check_map/verifaction_and_return_map.c srcs/check_map/utils1_cub3D.c srcs/check_map/check_the_map.c \
		srcs/check_map/check_is_element_and_return_it.c srcs/check_map/check_is_element_and_return_it-1.c \
		srcs/check_map/check_the_map-1.c srcs/check_map/check_space_is_protected.c

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
	@make clean -C ./inc/libft/
	rm -rf ${OBJM}

fclean : clean
	@make fclean -C ./inc/libft/
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re

	