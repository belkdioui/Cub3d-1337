# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 14:46:36 by bel-kdio          #+#    #+#              #
#    Updated: 2023/07/27 15:25:17 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_B = cub3D_bonus

LIBFT = ./inc/libft/libft.a

SRC = src/draw_map/initialization.c src/draw_map/drawing_game.c src/draw_map/mlx_utils.c \
		src/draw_map/key_hooks.c src/draw_map/key_hooks_utils.c\
		src/draw_map/cast_rays.c src/draw_map/cast_rays_utils.c src/draw_map/drawing_map_utils.c \
		inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c\
		src/map/verifaction_and_return_map.c src/map/utils1_cub3D.c src/map/check_the_map.c\
		src/map/check_is_element_and_return_it.c src/map/check_is_element_and_return_it-1.c\
		src/map/check_the_map-1.c src/map/check_space_is_protected.c

SRCM = cub3D.c ${SRC}

SRCB = cub3D_bonus.c ${SRC}

OBJ := $(SRCM:.c=.o)

OBJB := $(SRCB:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	${CC} -c $< -o $@


all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_B)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_B): $(OBJB)
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJB) $(LIBFT) -o $(NAME_B)

$(LIBFT):
	make -C inc/libft && make clean -C inc/libft

clean:
	$(RM) $(OBJ) $(OBJB) && make clean -C inc/libft

fclean:	clean
	$(RM) $(NAME) $(NAME_B) $(LIBFT)

re:	fclean all

bonus: all

.PHONY: all clean fclean re bonus