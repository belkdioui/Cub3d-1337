/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:04:20 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/13 23:52:01 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>

typedef struct s_ele
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
}	t_ele;

//utils
int		search_and_ret_place(char *av);
int		cal_number_of_lines_map(char **cnt_file);
void	free_db(char **arr);
//
int		space_is_protected(char **map, int x, int y);
int		check_rgb(char *rgb);
int		check_img(char *textures);
int		is_element(char *line, int *ele);
char	*ret_element(char *line, int num_of_ele);
char	*is_element_and_saveit(char **cnt_file, int which_ele,
			char ***save_map);
char	**ver_and_ret_map(int ac, char **av);
int		check_the_map(char **cnt_file, t_ele *ele);

#endif