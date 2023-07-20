/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/20 12:02:14 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	window_coloring(t_mlx *mlx_cub)
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

static void	drawing_square(t_mlx *mlx_cub, int x, int y)
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

static void	drawing_player(t_mlx *mlx_cub, int x, int y)
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

int draw_line(t_mlx *mlx_cub, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    if (pixels == 0) {
        my_mlx_pixel_put(&mlx_cub->data, beginX, beginY, color);
        return 0;
    }

    deltaX /= pixels;
    deltaY /= pixels;

    double pixelX = beginX;
    double pixelY = beginY;

    while (pixels) {
        my_mlx_pixel_put(&mlx_cub->data, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return 0;
}


void	drawing_map(char **map, t_mlx *mlx_cub)
{
	int	i;
	int	j;

	mlx_cub->x = 0;
	mlx_cub->y = -50;
	i = -1;
	window_coloring(mlx_cub);
	while (map[++i])
	{
		j = -1;
		mlx_cub->x = 0;
		mlx_cub->y += 50;
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				drawing_square(mlx_cub, mlx_cub->x, mlx_cub->y);
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				mlx_cub->x_p = mlx_cub->x + mlx_cub->x_p_move;
				mlx_cub->y_p = mlx_cub->y + mlx_cub->y_p_move;
				drawing_player(mlx_cub, mlx_cub->x_p, mlx_cub->y_p);
				float pdx = (mlx_cub->x_p + 5) + cos(mlx_cub->rot_pl) * 20;
				float pdy = (mlx_cub->y_p + 5) + sin(mlx_cub->rot_pl) * 20;
				draw_line(mlx_cub, mlx_cub->x_p + 5, mlx_cub->y_p + 5, pdx, pdy, 0x000000);
			}
			mlx_cub->x += 50;
		}
	}
}
