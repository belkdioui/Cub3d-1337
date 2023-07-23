/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/23 15:16:13 by bel-kdio         ###   ########.fr       */
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

float	calc_dist(float px, float py, float dx, float dy)
{
	float	a;
	float	b;
	float	c;

	a = (dx - px);
	b = (dy - py);
	c = sqrt((a * a) + (b * b));
	return (c);
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

int	draw_line(t_mlx *mlx_cub, int beginX, int beginY, int endX, int endY,
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
	if (pixels == 0)
	{
		my_mlx_pixel_put(&mlx_cub->data, beginX, beginY, color);
		return (0);
	}
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

void	cast_ray(t_mlx *mlx_cub, t_player *player, double ray_angle)
{
	double	wall_distance;

	wall_distance = 50;
	mlx_cub->pdx = cos(ray_angle) * wall_distance;
	mlx_cub->pdy = sin(ray_angle) * wall_distance;
	mlx_cub->endpoint_x = player->x + mlx_cub->pdx;
	mlx_cub->endpoint_y = player->y + mlx_cub->pdy;
}

void	drawing_map(char **map, t_mlx *mlx_cub, t_player *player)
{
	int		i;
	int		j;
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
	float	ra;

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
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				player->x = mlx_cub->x + 30 + mlx_cub->x_p_move;
				player->y = mlx_cub->y + 30 + mlx_cub->y_p_move;
				drawing_player(mlx_cub, player);
			}
			mlx_cub->x += 50;
		}
	}
	player->angle = mlx_cub->rot_pl;
	cast_ray(mlx_cub, player, player->angle);
	
	mlx_cub->x_p = player->x;
	mlx_cub->y_p = player->y;
	num_of_rays = 1920;
	dr = ((2 * PI) / num_of_rays) / ((float)360 / 90);
	ra = mlx_cub->rot_pl - (dr * num_of_rays / 2);
	if (ra > 2 * PI)
		ra -= 2 * PI;
	if (ra < 0)
		ra += 2 * PI;
	rays = 0;
	while (rays < num_of_rays)
	{
		dish = 100000000;
		disv = 100000000;
		dof = 0;
		atan = -1 / tan(ra);
		if (ra > PI)
		{
			ry = ((mlx_cub->y_p / 50) * 50) - 0.0001;
			rx = (mlx_cub->y_p - ry) * atan + (float)mlx_cub->x_p;
			yo = -50;
			xo = -yo * atan;
		}
		if (ra < PI)
		{
			ry = ((mlx_cub->y_p / 50) * 50) + 50;
			rx = (mlx_cub->y_p - ry) * atan + (float)mlx_cub->x_p;
			yo = 50;
			xo = -yo * atan;
		}
		if (ra == 0 || ra == (float)PI)
		{
			rx = (float)mlx_cub->x_p;
			ry = (float)mlx_cub->y_p;
			dof = mlx_cub->w / 50;
		}
		while (dof < mlx_cub->w / 50)
		{
			mx = (int)(rx / 50);
			my = (int)(ry / 50);
			if (mx >= 0 && mx < mlx_cub->w / 50 && my >= 0 && my < mlx_cub->h
				/ 50 && mlx_cub->ele->map[my][mx] == '1')
			{
				dof = mlx_cub->w / 50;
				hx = rx;
				hy = ry;
				dish = calc_dist(mlx_cub->x_p, mlx_cub->y_p, rx, ry);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		dof = 0;
		ntan = -tan(ra);
		if (ra > P2 && ra < P3)
		{
			rx = ((mlx_cub->x_p / 50) * 50) - 0.0001;
			ry = (mlx_cub->x_p - rx) * ntan + (float)mlx_cub->y_p;
			xo = -50;
			yo = -xo * ntan;
		}
		if (ra < P2 || ra > P3)
		{
			rx = ((mlx_cub->x_p / 50) * 50) + 50;
			ry = (mlx_cub->x_p - rx) * ntan + (float)mlx_cub->y_p;
			xo = 50;
			yo = -xo * ntan;
		}
		if (ra == 0 || ra == (float)PI)
		{
			rx = (float)mlx_cub->x_p;
			ry = (float)mlx_cub->y_p;
			dof = mlx_cub->w / 50;
		}
		while (dof < mlx_cub->w / 50)
		{
			mx = (int)(rx / 50);
			my = (int)(ry / 50);
			if (mx >= 0 && mx < mlx_cub->w / 50 && my >= 0 && my < mlx_cub->h
				/ 50 && mlx_cub->ele->map[my][mx] == '1')
			{
				dof = mlx_cub->w / 50;
				vx = rx;
				vy = ry;
				disv = calc_dist(mlx_cub->x_p, mlx_cub->y_p, rx, ry);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		if (dish < disv)
		{
			rx = hx;
			ry = hy;
			final_dis = dish;
		}
		else
		{
			rx = vx;
			ry = vy;
			final_dis = disv;
		}
		draw_line(mlx_cub, mlx_cub->x_p, mlx_cub->y_p, rx, ry, 0x0000FF);
		ra += dr;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		if (ra < 0)
			ra += 2 * PI;
		rays++;
	}
}
