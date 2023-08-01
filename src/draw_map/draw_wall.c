/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:55 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/01 11:02:12 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

unsigned int	rgbToHex(char *color_rgb)
{
	char	**split_color;
	int		rgb[3];

	split_color = ft_split(color_rgb, ',');
	rgb[0] = ft_atoi(split_color[0]);
	rgb[1] = ft_atoi(split_color[1]);
	rgb[2] = ft_atoi(split_color[2]);
	free_db(split_color);
	return (((rgb[0] & 0xFF) << 16) | ((rgb[1] & 0xFF) << 8) | (rgb[2] & 0xFF));
}

unsigned int	get_texture_pixel_color(t_data_tex text, int x, int y)
{
	unsigned int	hex_color;
	int				pos;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	pos = (y * text.line_length + x * (text.bits_per_pixel / 8));
	r = text.addr[pos + 2];
	g = text.addr[pos + 1];
	b = text.addr[pos];
	hex_color = (r << 16) | (g << 8) | b;
	return (hex_color);
}

void	init_utils_draw_3d(t_global *glob, t_map *map_draw)
{
	float	fish_eye;
	float	err;

	glob->rot_pl = map_draw->rot_pl;
	fish_eye = glob->ra - glob->rot_pl;
	glob->final_dis = map_draw->cast_ray->final_dis;
	glob->ra = map_draw->cast_ray->ra;
	glob->rays = map_draw->cast_ray->rays;
	glob->direction = map_draw->cast_ray->direction;
	glob->final_dis = (glob->final_dis * cos(fish_eye) / glob->map->h_sq);
	glob->lineH = height / (glob->final_dis);
	glob->color_floor = rgbToHex(glob->ele->f);
	glob->color_ciel = rgbToHex(glob->ele->c);
	glob->start = height / 2 - glob->lineH / 2;
	if (glob->start < 0)
		glob->start = 0;
	glob->floor = glob->lineH + glob->start;
	glob->texture_x = glob->map->cast_ray->ray_pos_x * ((float)glob->textures[2].wid / 10);
	err = glob->lineH / 2 - height / 2;
	if (err < 0)
		err = 0;
	glob->pixel = glob->textures[0].hei / glob->lineH;
	glob->y = err * glob->pixel;
}

void	draw_sky_and_floor(t_global *glob)
{
	while (glob->start > 0)
	{
		my_mlx_pixel_put(&glob->data, glob->map->cast_ray->rays, glob->start, glob->color_ciel);
		glob->start--;
	}
	while (glob->floor < height)
	{
		my_mlx_pixel_put(&glob->data, glob->map->cast_ray->rays, glob->floor, glob->color_floor);
		glob->floor++;
	}
}

void	draw_view(t_global *glob)
{
	int	i;

	i = 0;
	init_utils_draw_3d(glob, glob->map);
	while (i < glob->lineH && i < height)
	{
		if (glob->map->cast_ray->direction == 1)
		{
			glob->color = get_texture_pixel_color(glob->textures[0], glob->texture_x, glob->y);
			my_mlx_pixel_put(&glob->data, glob->rays, glob->start + i, glob->color);
		}
		else if (glob->map->cast_ray->direction == 2)
		{
			glob->color = get_texture_pixel_color(glob->textures[1], glob->texture_x, glob->y);
			my_mlx_pixel_put(&glob->data, glob->rays, glob->start + i, glob->color);
		}
		else if (glob->map->cast_ray->direction == 3)
		{
			glob->color = get_texture_pixel_color(glob->textures[2], glob->texture_x, glob->y);
			my_mlx_pixel_put(&glob->data, glob->rays, glob->start + i, glob->color);
		}
		else if (glob->map->cast_ray->direction == 4)
		{
			glob->color = get_texture_pixel_color(glob->textures[3], glob->texture_x, glob->y);
			my_mlx_pixel_put(&glob->data, glob->rays, glob->start + i, glob->color);
		}
		glob->y += glob->pixel;
		i++;
	}
}
