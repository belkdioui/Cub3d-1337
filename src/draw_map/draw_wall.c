/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:55 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/03 17:37:46 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

unsigned int	get_texture_pixel_color(t_data_tex text, int x, int y)
{
	unsigned int	hex_color;
	int				pos;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (y < 1000)
	{
		pos = (y * text.line_length + x * (text.bits_per_pixel / 8));
		r = text.addr[pos + 2];
		g = text.addr[pos + 1];
		b = text.addr[pos];
		hex_color = (r << 16) | (g << 8) | b;
	}
	return (hex_color);
}

void	init_utils_draw_3d(t_global *glob, t_map *map_draw)
{
	float	fish_eye;
	float	err;

	glob->rot_pl = map_draw->rot_pl;
	glob->ra = map_draw->cast_ray->ra;
	fish_eye = glob->ra - glob->rot_pl;
	glob->final_dis = map_draw->cast_ray->final_dis;
	glob->rays = map_draw->cast_ray->rays;
	glob->direction = map_draw->cast_ray->direction;
	glob->final_dis = (glob->final_dis * cos(fish_eye)) / glob->map->h_sq;
	glob->lineh = HEIGHT / (glob->final_dis);
	glob->color_floor = rgbtohex(glob->ele->f);
	glob->color_ciel = rgbtohex(glob->ele->c);
	glob->start = HEIGHT / 2 - glob->lineh / 2;
	if (glob->start < 0)
		glob->start = 0;
	glob->floor = glob->lineh + glob->start;
	glob->texture_x = glob->map->cast_ray->ray_pos_x
		* ((float)glob->textures[2].wid / 10);
	err = glob->lineh / 2 - HEIGHT / 2;
	if (err < 0)
		err = 0;
	glob->pixel = glob->textures[0].hei / glob->lineh;
	glob->y = err * glob->pixel - 1;
}

void	draw_sky_and_floor(t_global *glob)
{
	while (glob->start > 0 && glob->start < HEIGHT)
	{
		my_mlx_pixel_put(&glob->data, glob->map->cast_ray->rays, glob->start,
			glob->color_ciel);
		glob->start--;
	}
	while (glob->floor > 0 && glob->floor < HEIGHT)
	{
		my_mlx_pixel_put(&glob->data, glob->map->cast_ray->rays, glob->floor,
			glob->color_floor);
		glob->floor++;
	}
}

void	get_the_color_and_put_it(t_global *glob, int i, t_data_tex text)
{
	glob->color = get_texture_pixel_color(text,
			glob->texture_x, glob->y);
	my_mlx_pixel_put(&glob->data, glob->rays, glob->start + i,
		glob->color);
}

void	draw_view(t_global *glob)
{
	int	i;

	i = 0;
	init_utils_draw_3d(glob, glob->map);
	while (i < glob->lineh && i < HEIGHT)
	{
		if (glob->map->cast_ray->direction == 1)
			get_the_color_and_put_it(glob, i, glob->textures[0]);
		else if (glob->map->cast_ray->direction == 2)
			get_the_color_and_put_it(glob, i, glob->textures[1]);
		else if (glob->map->cast_ray->direction == 3)
			get_the_color_and_put_it(glob, i, glob->textures[2]);
		else if (glob->map->cast_ray->direction == 4)
			get_the_color_and_put_it(glob, i, glob->textures[3]);
		glob->y += glob->pixel;
		i++;
	}
	draw_sky_and_floor(glob);
}
