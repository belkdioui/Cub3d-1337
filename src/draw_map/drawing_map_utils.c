/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/24 14:47:02 by rrhnizar         ###   ########.fr       */
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

static void	drawing_player(t_mlx *mlx_cub)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = mlx_cub->x_p - 20 / 2;
	y = mlx_cub->y_p - 20 / 2;
	i = 0;
	while (x + 20 <= mlx_cub->w && i < 20)
	{
		j = 0;
		while (y + 20 <= mlx_cub->h && j < 20)
		{
			my_mlx_pixel_put(&mlx_cub->data, x + i, y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

int	draw_line(t_mlx *mlx_cub, int beginX, int beginY, int endX, int endY, \
	int color)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = endX - beginX;
	deltay = endY - beginY;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = beginX;
	pixely = beginY;
	while (pixels)
	{
		if (pixelx >= 0 && pixelx < mlx_cub->w && pixely >= 0
			&& pixely < mlx_cub->h)
			my_mlx_pixel_put(&mlx_cub->data, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return (0);
}

void	drawing_map(char **map, t_mlx *mlx_cub)
{
	int		i;
	int		j;

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
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				mlx_cub->x_p = mlx_cub->x + mlx_cub->x_p_move;
				mlx_cub->y_p = mlx_cub->y + mlx_cub->y_p_move;
				drawing_player(mlx_cub);
			}
			mlx_cub->x += 50;
		}
	}
	cast_rays(mlx_cub);
}
