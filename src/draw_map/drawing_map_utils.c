/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/17 19:59:58 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	window_coloring(t_mlx *mlx_cub)
{
	int	x;
	int	y;

	x = 0;
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
	while (tmp_x++ < x + 10 && x + 10 <= mlx_cub->w)
	{
		tmp_y = y;
		while (tmp_y++ < y + 10 && y + 10 <= mlx_cub->h)
			my_mlx_pixel_put(&mlx_cub->data, tmp_x, tmp_y, 0xFF0000);
	}
}

void	drawing_map(char **map, t_mlx *mlx_cub)
{
	int	i;
	int	j;

	mlx_cub->x = 0;
	mlx_cub->y = -50;
	i = 0;
	window_coloring(mlx_cub);
	while (map[i])
	{
		j = 0;
		mlx_cub->x = 0;
		mlx_cub->y += 50;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				drawing_square(mlx_cub, mlx_cub->x, mlx_cub->y);
			else if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (map[(mlx_cub->y + (int)mlx_cub->y_player) / 50] \
				&& map[(mlx_cub->y + (int)mlx_cub->y_player) / 50][(mlx_cub->x + (int)mlx_cub->x_player) / 50] == '1')
				{
					printf("%d\n", mlx_cub->y_p);
					drawing_player(mlx_cub, mlx_cub->x_p, mlx_cub->y_p);
				}
				else
				{
					mlx_cub->x_p = mlx_cub->x + mlx_cub->x_player;
					mlx_cub->y_p = mlx_cub->y + mlx_cub->y_player;
					drawing_player(mlx_cub, mlx_cub->x + mlx_cub->x_player, mlx_cub->y + mlx_cub->y_player);
				}
			}
			mlx_cub->x += 50;
			j++;
		}
		i++;
	}
}
