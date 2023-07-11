# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 14:46:36 by bel-kdio          #+#    #+#              #
#    Updated: 2023/07/11 20:09:02 by bel-kdio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = ./inc/libft/libft.a

SRC = src/cub3D.c inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c src/verifaction_and_return_map.c src/utils1_cub3D.c src/check_the_map.c

OBJ := $(SRC:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./inc/libft/
	$(CC) $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

clean:
	@make clean -C ./inc/libft/
	$(RM) $(OBJ)

fclean:	clean
	@make fclean -C ./inc/libft/
	$(RM) $(NAME)

re:	fclean all

bonus: all

.PHONY: all clean fclean re bonus