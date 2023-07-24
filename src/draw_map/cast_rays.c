/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:19:10 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/24 14:49:15 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	check_horiental(t_mlx *mlx_cub, t_cast_ray *ca_ray)
{
	ca_ray->dof = 0;
	ca_ray->atan = -1 / tan(ca_ray->ra);
	if (ca_ray->ra > PI)
	{
		ca_ray->ry = ((mlx_cub->y_p / 50) * 50) - 0.0001;
		ca_ray->rx = (mlx_cub->y_p - ca_ray->ry) * \
				ca_ray->atan + (float)mlx_cub->x_p;
		ca_ray->yo = -50;
		ca_ray->xo = -ca_ray->yo * ca_ray->atan;
	}
	if (ca_ray->ra < PI)
	{
		ca_ray->ry = ((mlx_cub->y_p / 50) * 50) + 50;
		ca_ray->rx = (mlx_cub->y_p - ca_ray->ry) * \
			ca_ray->atan + (float)mlx_cub->x_p;
		ca_ray->yo = 50;
		ca_ray->xo = -ca_ray->yo * ca_ray->atan;
	}
	if (ca_ray->ra == 0 || ca_ray->ra == (float)PI)
	{
		ca_ray->rx = (float)mlx_cub->x_p;
		ca_ray->ry = (float)mlx_cub->y_p;
		ca_ray->dof = mlx_cub->w / 50;
	}
	while (ca_ray->dof < mlx_cub->w / 50)
	{
		ca_ray->mx = (int)(ca_ray->rx / 50);
		ca_ray->my = (int)(ca_ray->ry / 50);
		if (ca_ray->mx >= 0 && ca_ray->mx < mlx_cub->w / 50 \
			&& ca_ray->my >= 0 && ca_ray->my < mlx_cub->h
			/ 50 && mlx_cub->ele->map[ca_ray->my][ca_ray->mx] == '1')
		{
			ca_ray->dof = mlx_cub->w / 50;
			ca_ray->hx = ca_ray->rx;
			ca_ray->hy = ca_ray->ry;
			ca_ray->dish = calc_dist(mlx_cub->x_p, mlx_cub->y_p, \
				ca_ray->rx, ca_ray->ry);
		}
		else
		{
			ca_ray->rx += ca_ray->xo;
			ca_ray->ry += ca_ray->yo;
			ca_ray->dof += 1;
		}
	}
}

void	check_vertical(t_mlx *mlx_cub, t_cast_ray *ca_ray)
{
	ca_ray->dof = 0;
	ca_ray->ntan = -tan(ca_ray->ra);
	if (ca_ray->ra > P2 && ca_ray->ra < P3)
	{
		ca_ray->rx = ((mlx_cub->x_p / 50) * 50) - 0.0001;
		ca_ray->ry = (mlx_cub->x_p - ca_ray->rx) * \
			ca_ray->ntan + (float)mlx_cub->y_p;
		ca_ray->xo = -50;
		ca_ray->yo = -ca_ray->xo * ca_ray->ntan;
	}
	if (ca_ray->ra < P2 || ca_ray->ra > P3)
	{
		ca_ray->rx = ((mlx_cub->x_p / 50) * 50) + 50;
		ca_ray->ry = (mlx_cub->x_p - ca_ray->rx) * \
			ca_ray->ntan + (float)mlx_cub->y_p;
		ca_ray->xo = 50;
		ca_ray->yo = -ca_ray->xo * ca_ray->ntan;
	}
	if (ca_ray->ra == 0 || ca_ray->ra == (float)PI)
	{
		ca_ray->rx = (float)mlx_cub->x_p;
		ca_ray->ry = (float)mlx_cub->y_p;
		ca_ray->dof = mlx_cub->w / 50;
	}
	while (ca_ray->dof < mlx_cub->w / 50)
	{
		ca_ray->mx = (int)(ca_ray->rx / 50);
		ca_ray->my = (int)(ca_ray->ry / 50);
		if (ca_ray->mx >= 0 && ca_ray->mx < mlx_cub->w / 50 && \
			ca_ray->my >= 0 && ca_ray->my < mlx_cub->h
			/ 50 && mlx_cub->ele->map[ca_ray->my][ca_ray->mx] == '1')
		{
			ca_ray->dof = mlx_cub->w / 50;
			ca_ray->vx = ca_ray->rx;
			ca_ray->vy = ca_ray->ry;
			ca_ray->disv = calc_dist(mlx_cub->x_p, mlx_cub->y_p, \
				ca_ray->rx, ca_ray->ry);
		}
		else
		{
			ca_ray->rx += ca_ray->xo;
			ca_ray->ry += ca_ray->yo;
			ca_ray->dof += 1;
		}
	}
}

void	cast_rays(t_mlx *mlx_cub)
{
	mlx_cub->cast_ray = init_strcut_cast_ray(mlx_cub);
	while (mlx_cub->cast_ray->rays < mlx_cub->cast_ray->num_of_rays)
	{
		mlx_cub->cast_ray->dish = 100000000;
		mlx_cub->cast_ray->disv = 100000000;
		check_horiental(mlx_cub, mlx_cub->cast_ray);
		check_vertical(mlx_cub, mlx_cub->cast_ray);
		if (mlx_cub->cast_ray->dish < mlx_cub->cast_ray->disv)
		{
			mlx_cub->endpoint_x = mlx_cub->cast_ray->hx;
			mlx_cub->endpoint_y = mlx_cub->cast_ray->hy;
			mlx_cub->cast_ray->final_dis = mlx_cub->cast_ray->dish;
		}
		else
		{
			mlx_cub->endpoint_x = mlx_cub->cast_ray->vx;
			mlx_cub->endpoint_y = mlx_cub->cast_ray->vy;
			mlx_cub->cast_ray->final_dis = mlx_cub->cast_ray->disv;
		}
		draw_line(mlx_cub, mlx_cub->x_p, mlx_cub->y_p, \
			mlx_cub->endpoint_x, mlx_cub->endpoint_y, 0x4ff507);
		mlx_cub->cast_ray->ra += mlx_cub->cast_ray->dr;
		if (mlx_cub->cast_ray->ra > 2 * PI)
			mlx_cub->cast_ray->ra -= 2 * PI;
		if (mlx_cub->cast_ray->ra < 0)
			mlx_cub->cast_ray->ra += 2 * PI;
		mlx_cub->cast_ray->rays++;
	}
}
