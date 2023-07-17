/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/17 12:04:57 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	search_beginning_the_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == '1')
			return (i);
		i++;
	}
	return (0);
}

void	window_coloring(t_mlx *mlx_cub)
{
	int	x;
	int	y;

	x = 0;
	// printf("%d\n", mlx_cub->data.bits_per_pixel);
	while (x < mlx_cub->w)
	{
		y = 0;
		while (y < mlx_cub->h)
		{
			my_mlx_pixel_put(&mlx_cub->data, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

void	drawing_square(t_mlx *mlx_cub, int x, int y)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	while (tmp_x++ < x + 49 && x + 50 <= mlx_cub->w)
	{
		tmp_y = y;
		while (tmp_y++ < y + 49 && y + 50 <= mlx_cub->h)
			my_mlx_pixel_put(&mlx_cub->data, tmp_x, tmp_y, 0x000000);
	}
}

void	drawing_player(t_mlx *mlx_cub, int x, int y)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	while (tmp_x++ < x + 20 && x + 20 <= mlx_cub->w)
	{
		tmp_y = y;
		while (tmp_y++ < y + 20 && y + 20 <= mlx_cub->h)
			my_mlx_pixel_put(&mlx_cub->data, tmp_x, tmp_y, 0xFF0000);
	}
}

void	drawing_map(char **map, t_mlx *mlx_cub)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = -50;
	i = search_beginning_the_map(map);
	window_coloring(mlx_cub);
	while (map[i])
	{
		j = 0;
		x = 0;
		y += 50;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				drawing_square(mlx_cub, x, y);
			else if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				printf("%c\n", map[i -1][j]);
				// exit(1);
				// mlx_cub->y_up = map[i -1][j];
				// mlx_cub->y_down = map[i +1][j];
				// mlx_cub->x_right = map[i][j +1];
				// mlx_cub->x_left = map[i][j -1];
				// mlx_cub->y_up = '1';
				// mlx_cub->y_down = '1';
				// mlx_cub->x_right = '1';
				// mlx_cub->x_left = '1';
				drawing_player(mlx_cub, x + mlx_cub->x_player, y + mlx_cub->y_player);
			}
			x += 50;
			j++;
		}
		i++;
	}
}
