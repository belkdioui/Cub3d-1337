/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:40 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/03 17:43:36 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

t_cast_ray	*init_strcut_cast_ray(t_map *map_draw)
{
	t_cast_ray	*ca_ray;

	ca_ray = malloc(sizeof(t_cast_ray));
	if (!ca_ray)
		exit(1);
	ca_ray->num_of_rays = 1920;
	ca_ray->dr = ((PI / 180) * 60) / ca_ray->num_of_rays;
	ca_ray->ra = map_draw->rot_pl - ((PI / 180) * 60) / 2;
	if (ca_ray->ra > 2 * PI)
		ca_ray->ra -= 2 * PI;
	if (ca_ray->ra < 0)
		ca_ray->ra += 2 * PI;
	ca_ray->rays = 0;
	map_draw->pdx = cos(map_draw->rot_pl) * 4;
	map_draw->pdy = sin(map_draw->rot_pl) * 4;
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

void	set_the_min_pos(t_map *map_draw)
{
	if (map_draw->cast_ray->dish < map_draw->cast_ray->disv)
	{
		if (map_draw->cast_ray->ra > M_PI)
			map_draw->cast_ray->direction = 1;
		else
			map_draw->cast_ray->direction = 2;
		map_draw->cast_ray->ray_pos_x = map_draw->cast_ray->hx
			- (int)(map_draw->cast_ray->hx / 10) * 10;
		map_draw->endpoint_x = map_draw->cast_ray->hx;
		map_draw->endpoint_y = map_draw->cast_ray->hy;
		map_draw->cast_ray->final_dis = map_draw->cast_ray->dish;
	}
	else
	{
		if (map_draw->cast_ray->ra > M_PI / 2 && map_draw->cast_ray->ra < (3
				* M_PI / 2))
			map_draw->cast_ray->direction = 3;
		else
			map_draw->cast_ray->direction = 4;
		map_draw->cast_ray->ray_pos_x = map_draw->cast_ray->vy
			- (int)(map_draw->cast_ray->vy / 10) * 10;
		map_draw->endpoint_x = map_draw->cast_ray->vx;
		map_draw->endpoint_y = map_draw->cast_ray->vy;
		map_draw->cast_ray->final_dis = map_draw->cast_ray->disv;
	}
}
