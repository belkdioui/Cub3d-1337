/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:40 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/29 18:21:17 by rrhnizar         ###   ########.fr       */
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
	ca_ray->dr = ((2 * PI) / ca_ray->num_of_rays) / ((float)360 / 90);
	ca_ray->ra = map_draw->rot_pl - (ca_ray->dr * ca_ray->num_of_rays / 2);
	if (ca_ray->ra > 2 * PI)
		ca_ray->ra -= 2 * PI;
	if (ca_ray->ra < 0)
		ca_ray->ra += 2 * PI;
	ca_ray->rays = 0;
	map_draw->pdx = cos(map_draw->rot_pl) * 3;
	map_draw->pdy = sin(map_draw->rot_pl) * 3;
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
		map_draw->endpoint_x = map_draw->cast_ray->hx;
		map_draw->endpoint_y = map_draw->cast_ray->hy;
		map_draw->cast_ray->final_dis = map_draw->cast_ray->dish;
	}
	else
	{
		map_draw->endpoint_x = map_draw->cast_ray->vx;
		map_draw->endpoint_y = map_draw->cast_ray->vy;
		map_draw->cast_ray->final_dis = map_draw->cast_ray->disv;
	}
}
