/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:04:20 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/08/03 19:10:05 by rrhnizar         ###   ########.fr       */
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

# define HEIGHT 1080
# define WIDTH 1920
# define HEIGHT_MAP 250
# define WIDTH_MAP 350

# define ESC 53
# define PI M_PI
# define W 13
# define A 0
# define S 1
# define D 2
# define ON_DESTROY 17
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123

/*---------- struct cast rays ---------*/
typedef struct s_cast_ray
{
	int		num_of_rays;
	float	dr;
	int		rays;
	float	ry;
	float	rx;
	float	dish;
	float	hx;
	float	hy;
	float	disv;
	float	vx;
	float	vy;
	float	final_dis;
	float	atan;
	float	ntan;
	int		dof;
	int		mx;
	int		my;
	float	xo;
	float	yo;
	int		direction;
	float	ray_pos_x;
	float	ra;
}				t_cast_ray;

/*-------- struct the textures -------------*/

typedef struct s_data_tex
{
	char		*dire;
	void		*img;
	char		*addr;
	int			wid;
	int			hei;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data_tex;

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

typedef struct s_map
{
	int			w;
	int			h;
	int			x;
	int			y;
	int			x_p;
	int			y_p;
	int			w_sq;
	int			h_sq;
	double		x_p_move;
	double		y_p_move;
	double		pdx;
	double		pdy;
	double		endpoint_x;
	double		endpoint_y;
	t_data		data;
	t_cast_ray	*cast_ray;
	float		rot_pl;
	int			i;
	int			j;
}			t_map;

/*--------- strcut the mlx -----------*/

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_data		data;
	t_data		data2;
}				t_mlx;

typedef struct s_global
{
	t_mlx			*mlx_cub;
	t_map			*map;
	t_ele			*ele;
	float			rot_pl;
	int				num_of_player;
	float			ra;
	int				rays;
	t_data_tex		*textures;
	t_data			data;
	float			final_dis;
	int				direction;
	float			lineh;
	unsigned int	color_floor;
	unsigned int	color_ciel;
	unsigned int	color;
	float			start;
	float			floor;
	float			y;
	float			texture_x;
	float			pixel;
}				t_global;

typedef struct s_vars
{
	int			i;
	int			j;
	int			is_ele;
	int			check;
	int			check_1;
	int			check_2;
}				t_vars;

// utils
int				search_and_ret_place(char *av);
int				cal_number_of_lines_map(char **cnt_file);
void			free_db(char **arr);
int				len_of_longest_line(char **pre_map);
void			free_data_textures(t_global *glob);
//
int				space_is_protected(char **map, int x, int y);
int				if_bet_first_and_last(char **map, int i, int *j,
					t_global *glob);
char			**allocate_save_map(char **cnt_file);
unsigned int	rgbtohex(char *color_rgb);
int				check_rgb(char *rgb);
int				check_img(char *textures);
int				is_element(char *line, int *ele);
char			*ret_element(char *line, int num_of_ele);
char			*is_element_and_saveit(char **cnt_file, int which_ele,
					char ***save_map);
char			**ver_and_ret_map(int ac, char **av);
int				check_the_map(char **cnt_file, t_ele *ele, t_global *glob);
/*----- mlx utils -------*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				close_window(t_global *glob);
int				key_hock(int keycode, t_global *glob);

/*----- drawing map -------*/
t_ele			*get_map(int ac, char **av, t_global *glob);
void			free_ele(t_ele *ele);
void			cast_rays(t_global *glob, t_map *map_draw, char **map);
int				draw_line(t_map *map_draw, int beginX, int beginY);

/*-------- cast rays ------------*/
t_cast_ray		*init_strcut_cast_ray(t_map *map_draw);
float			calc_dist(float px, float py, float dx, float dy);
void			set_the_min_pos(t_map *map_draw);

/*--------- key hooks ------------*/
void			key_w(t_map *map_draw, char **map, int tmp_xp, int tmp_yp);
void			key_s(t_map *map_draw, char **map, int tmp_xp, int tmp_yp);
void			key_a(t_map *map_draw, char **map, int tmp_xp, int tmp_yp);
void			key_d(t_map *map_draw, char **map, int tmp_xp, int tmp_yp);

/*--------- last update ------------*/
t_global		*init_global(t_global *glob, int ac, char **av);
void			draw_map(t_global *glob, t_map *map_draw, char **map);
t_ele			*get_map(int ac, char **av, t_global *glob);
void			finish(t_global *glob);
void			check_size(t_global *glob, t_map *map_draw);
void			draw(t_global *glob);
t_mlx			*init_mlx(void);
void			free_all(t_global *global);
void			draw_view(t_global *glob);

#endif