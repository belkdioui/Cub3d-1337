/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:40 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/24 16:51:56 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

t_cast_ray	*init_strcut_cast_ray(t_mlx *mlx_cub)
{
	t_cast_ray	*ca_ray;

	ca_ray = malloc(sizeof(t_cast_ray));
	if (!ca_ray)
	{
		free(mlx_cub);
		exit(1);
	}
	ca_ray->num_of_rays = 1920;
	ca_ray->dr = ((2 * PI) / ca_ray->num_of_rays) / ((float)360 / 90);
	ca_ray->ra = mlx_cub->rot_pl - (ca_ray->dr * ca_ray->num_of_rays / 2);
	if (ca_ray->ra > 2 * PI)
		ca_ray->ra -= 2 * PI;
	if (ca_ray->ra < 0)
		ca_ray->ra += 2 * PI;
	ca_ray->rays = 0;
	mlx_cub->pdx = cos(mlx_cub->rot_pl) * 6;
	mlx_cub->pdy = sin(mlx_cub->rot_pl) * 6;
	return (ca_ray);
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

void	set_the_min_pos(t_mlx *mlx_cub)
{
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
}
