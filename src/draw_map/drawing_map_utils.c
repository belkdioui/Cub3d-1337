/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/22 21:41:44 by rrhnizar         ###   ########.fr       */
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

static void	drawing_player(t_mlx *mlx_cub, t_player *player)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = player->x - player->player_size / 2;
	y = player->y - player->player_size / 2;
	i = 0;
	while (x + player->player_size <= mlx_cub->w && i < player->player_size)
	{
		j = 0;
		while (y + player->player_size <= mlx_cub->h && j < player->player_size)
		{
			my_mlx_pixel_put(&mlx_cub->data, x + i, y + j, 0xFF0000);
			j++;
		}
		i++;
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

void cast_ray(t_mlx *mlx_cub, t_player *player, double ray_angle) 
{
    double wall_distance = 50; // Distance from the player to the wall

    mlx_cub->pdx = cos(ray_angle) * wall_distance;
    mlx_cub->pdy = sin(ray_angle) * wall_distance;
    mlx_cub->endpoint_x = player->x + mlx_cub->pdx;
    mlx_cub->endpoint_y = player->y + mlx_cub->pdy;
	draw_line(mlx_cub, player->x, player->y, mlx_cub->endpoint_x, mlx_cub->endpoint_y, 0x4ff507);
}

double degreesToRadians(double degrees) 
{
    return (degrees * (M_PI / 180.0));
}

void	drawing_map(char **map, t_mlx *mlx_cub, t_player *player)
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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				player->x = mlx_cub->x + 30 + mlx_cub->x_p_move;
				player->y = mlx_cub->y + 30 + mlx_cub->y_p_move;
				drawing_player(mlx_cub, player);
			}
			mlx_cub->x += 50;
		}
	}
	double angle_radians = degreesToRadians(FOV_ANGLE);
	player->angle = mlx_cub->rot_pl;
	cast_ray(mlx_cub, player, player->angle);
	while(angle_radians >= -angle_radians)
	{
		float pdx_top = mlx_cub->endpoint_x + cos(mlx_cub->rot_pl + angle_radians) * 50;
		float pdy_top = mlx_cub->endpoint_y + sin(mlx_cub->rot_pl + angle_radians) * 50;
		float pdx_bottom = mlx_cub->endpoint_x + cos(mlx_cub->rot_pl - angle_radians) * 50;
		float pdy_bottom = mlx_cub->endpoint_y + sin(mlx_cub->rot_pl - angle_radians) * 50;
		draw_line(mlx_cub, player->x, player->y, mlx_cub->endpoint_x, mlx_cub->endpoint_y, 0x4ff507);
		draw_line(mlx_cub, player->x, player->y, pdx_top, pdy_top, 0x4ff507);
		draw_line(mlx_cub, player->x, player->y, pdx_bottom, pdy_bottom, 0x4ff507);
		angle_radians -= 0.0008;
	}
	
	// double step_size = 1.0;
	// cast_ray(mlx_cub, player, player->angle_end);
	// if (player->angle_start == 0)
	// {
	// 	while (fabs(player->angle_start) <= fabs(player->angle_end))
	// 	{
	// 		cast_ray(mlx_cub, player, player->angle_start);
	// 		player->angle_start -= degreesToRadians(step_size);
	// 	}
	// }
	// else
	// {
	// 	while (fabs(player->angle_start) >= fabs(player->angle_end))
	// 	{
	// 		cast_ray(mlx_cub, player, player->angle_start);
	// 		player->angle_start -= degreesToRadians(step_size);
	// 	}
	// }
}
