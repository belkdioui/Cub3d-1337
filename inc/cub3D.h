/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:04:20 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/18 11:28:32 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>

# define ESC 53
# define ON_DESTROY 17
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT  123

/*----- data the my_mlx_pixel_put --------*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_ele
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	char	*str;
}	t_ele;

/*--------- strcut the mlx -----------*/

typedef struct s_mlx
{
	int			w;
	int			h;
	void		*mlx_ptr;
	void		*mlx_win;
	int			x;
	int			y;
	double		x_p_move;
	double		y_p_move;
	int			x_p;
	int			y_p;
	t_data		data;
	t_ele		*ele;
}				t_mlx;

typedef struct s_vars
{
	int		i;
	int		j;
	int		is_ele;
	int		check;
}	t_vars;


//utils
int		search_and_ret_place(char *av);
int		cal_number_of_lines_map(char **cnt_file);
void	free_db(char **arr);
int		len_of_longest_line(char **pre_map);
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

/*----- mlx utils -------*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(t_mlx *mlx_cub);
int		key_hock(int keycode, t_mlx *mlx_cub);

/*----- drawing map -------*/
t_ele	*get_map(int ac, char **av);
void	init(t_mlx *mlx_cub, char **map);
void	drawing_map(char **map, t_mlx *mlx_cub);
#endif