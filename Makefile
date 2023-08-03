# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 14:46:36 by bel-kdio          #+#    #+#              #
#    Updated: 2023/08/03 18:28:43 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D


LIBFT = ./inc/libft/libft.a

SRC = cub3D.c src/draw_map/initialization.c src/draw_map/drawing_game.c src/draw_map/mlx_utils.c \
		src/draw_map/key_hooks.c src/draw_map/key_hooks_utils.c src/draw_map/initialization2.c\
		src/draw_map/draw_wall.c src/draw_map/mlx_utils_2.c\
		src/draw_map/cast_rays.c src/draw_map/cast_rays_utils.c src/draw_map/drawing_map_utils.c \
		inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c\
		src/map/verifaction_and_return_map.c src/map/utils1_cub3D.c src/map/check_the_map.c\
		src/map/check_is_element_and_return_it.c src/map/check_is_element_and_return_it-1.c\
		src/map/check_the_map-1.c src/map/check_space_is_protected.c

OBJ := $(SRC:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	${CC} -c $< -o $@

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME)

$(LIBFT):
	make -C inc/libft && make clean -C inc/libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJB) && make clean -C inc/libft

fclean:	clean
	$(RM) $(NAME) $(NAME_B) $(LIBFT)

re:	fclean all

bonus: all

.PHONY: all clean fclean re bonus
