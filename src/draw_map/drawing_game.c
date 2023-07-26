/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:27:08 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/26 17:00:21 by rrhnizar         ###   ########.fr       */
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

static void	img_coloring_map(t_data *data, int w, int h)
{
	int	x;
	int	y;

	x = 0;
	while (x < w - 1)
	{
		y = 0;
		while (y < h - 1)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
			y++;
		}
		x++;
	}
	y = 0;
	while (y < h - 1)
		my_mlx_pixel_put(data, x, y++, 0xe3cd81);
	x = 0;
	while (x < w)
		my_mlx_pixel_put(data, x++, y, 0xe3cd81);
}

void	drawing_square(t_game *game, int x, int y)
{
	int	tmp_x;
	int	tmp_y;

	tmp_y = y;
	while (tmp_y < (y + game->h_sq - 1) && (y + game->h_sq) <= game->h)
	{
		tmp_x = x;
		while (tmp_x < (x + game->w_sq - 1) && (x + game->w_sq) <= width)
		{
			my_mlx_pixel_put(&game->data, tmp_x, tmp_y, 0x00cc1a);
			tmp_x++;
		}
		tmp_y++;
	}
}

void	drawing_player(t_game *game, int i, int j)
{
	int	x;
	int	y;
	int	h_p;
	int	w_p;

	h_p = game->h_sq / 5;
	w_p = game->w_sq / 3;
	x = game->x_p - (w_p / 2);
	y = game->y_p - (h_p / 2);
	while (y + h_p < height && i < h_p)
	{
		j = 0;
		while (x + w_p < width && j < w_p)
		{
			my_mlx_pixel_put(&game->data, x + j, y + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

// void	init_necessary(t_gloabl *glob, t_game *game)
// {
	// game->x = 0;
	// game->y = -game->h_sq;
// 	game->rot_pl = glob->rot_pl;
// }

void	draw_game(t_game *game, char **map)
{
	int		i;
	int		j;

	i = -1;
	game->x = 0;
	game->y = -game->h_sq;
	img_coloring(&game->data, game->w, game->h);
	img_coloring_map(&game->data, game->w, game->h);
	while (map[++i])
	{
		j = -1;
		game->x = 0;
		game->y += game->h_sq;
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				drawing_square(game, game->x, game->y);
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				game->x_p = game->x + (game->w_sq / 2) + game->x_p_move;
				game->y_p = game->y + (game->h_sq / 2) + game->y_p_move;
				drawing_player(game, 0, 0);
			}
			game->x += game->w_sq;
		}
	}
	cast_rays(game, map);
}
