# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 14:46:36 by bel-kdio          #+#    #+#              #
#    Updated: 2023/07/24 17:26:54 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = ./inc/libft/libft.a

SRC = src/draw_map/initialization.c src/draw_map/mlx_utils.c src/draw_map/drawing_map_utils.c\
		src/draw_map/key_hooks.c src/draw_map/cast_rays.c src/draw_map/cast_rays_utils.c\
		src/draw_map/key_hooks_utils.c\
		cub3D.c inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c\
		src/map/verifaction_and_return_map.c src/map/utils1_cub3D.c src/map/check_the_map.c\
		src/map/check_is_element_and_return_it.c src/map/check_is_element_and_return_it-1.c\
		src/map/check_the_map-1.c src/map/check_space_is_protected.c 

OBJ := $(SRC:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./inc/libft/
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@make clean -C ./inc/libft/
	$(RM) $(OBJ)

fclean:	clean
	@make fclean -C ./inc/libft/
	$(RM) $(NAME)

re:	fclean all

bonus: all

.PHONY: all clean fclean re bonus