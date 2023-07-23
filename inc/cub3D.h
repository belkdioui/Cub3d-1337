/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:04:20 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/23 15:07:55 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define ESC 53
# define PI M_PI
# define P2 (M_PI / 2)
# define P3 (3 * (M_PI / 2))
# define W 13
# define A 0
# define S 1
# define D 2
# define ON_DESTROY 17
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123

/*----------- struct the player ------------*/

typedef struct s_player
{
	double		x;
	double		y;
	double		angle;
	int			player_size;
}				t_player;

/*----- data the my_mlx_pixel_put --------*/

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_ele
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
	char		*str;
}				t_ele;

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
	float		rot_pl;
	t_player	*player;
	double		pdx;
	double		pdy;
	double		endpoint_x;
	double		endpoint_y;
	t_data		data;
	t_ele		*ele;
}				t_mlx;

typedef struct s_vars
{
	int			i;
	int			j;
	int			is_ele;
	int			check;
}				t_vars;

// utils
int				search_and_ret_place(char *av);
int				cal_number_of_lines_map(char **cnt_file);
void			free_db(char **arr);
int				len_of_longest_line(char **pre_map);
//
int				space_is_protected(char **map, int x, int y);
int				check_rgb(char *rgb);
int				check_img(char *textures);
int				is_element(char *line, int *ele);
char			*ret_element(char *line, int num_of_ele);
char			*is_element_and_saveit(char **cnt_file, int which_ele,
					char ***save_map);
char			**ver_and_ret_map(int ac, char **av);
int				check_the_map(char **cnt_file, t_ele *ele, t_mlx *mlx_cub);
/*----- mlx utils -------*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				close_window(t_mlx *mlx_cub);
int				key_hock(int keycode, t_mlx *mlx_cub);

/*----- drawing map -------*/
t_ele			*get_map(int ac, char **av, t_mlx *mlx_cub);
void			init(t_mlx *mlx_cub, char **map, t_player *player);
void			drawing_map(char **map, t_mlx *mlx_cub, t_player *player);

void			free_ele(t_ele *ele);
#endif