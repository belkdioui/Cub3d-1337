/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:27:08 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/03 12:26:20 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	img_coloring(t_data *data, int w, int h)
{
	int	x;
	int	y;

	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void	drawing_square(t_map *map_draw, int x, int y)
{
	int	tmp_x;
	int	tmp_y;

	tmp_y = y;
	while (tmp_y < (y + map_draw->h_sq - 1) && (y
			+ map_draw->h_sq) <= map_draw->h)
	{
		tmp_x = x;
		while (tmp_x < (x + map_draw->w_sq - 1) && (x
				+ map_draw->w_sq) <= map_draw->w)
		{
			my_mlx_pixel_put(&map_draw->data, tmp_x, tmp_y, 0x00cc1a);
			tmp_x++;
		}
		tmp_y++;
	}
}

void	drawing_player(t_map *map_draw, int i, int j)
{
	int	x;
	int	y;
	int	h_p;
	int	w_p;

	h_p = map_draw->h_sq / 2;
	w_p = map_draw->w_sq / 2;
	x = map_draw->x_p - (w_p / 2);
	y = map_draw->y_p - (h_p / 2);
	while (y + h_p < map_draw->h && i < h_p)
	{
		j = 0;
		while (x + w_p < map_draw->w && j < w_p)
		{
			my_mlx_pixel_put(&map_draw->data, x + j, y + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	if_player(t_map *map_draw)
{
	map_draw->x_p = map_draw->x + (map_draw->w_sq / 2) + map_draw->x_p_move;
	map_draw->y_p = map_draw->y + (map_draw->h_sq / 2) + map_draw->y_p_move;
	drawing_player(map_draw, 0, 0);
}

void	draw_map(t_global *glob, t_map *map_draw, char **map)
{
	int	i;
	int	j;

	i = -1;
	map_draw->x = 0;
	map_draw->y = -map_draw->h_sq;
	img_coloring(&map_draw->data, map_draw->w, map_draw->h);
	while (map[++i])
	{
		j = -1;
		map_draw->x = 0;
		map_draw->y += map_draw->h_sq;
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				drawing_square(map_draw, map_draw->x, map_draw->y);
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				if_player(map_draw);
			map_draw->x += map_draw->w_sq;
		}
	}
	cast_rays(glob, map_draw, map);
}
