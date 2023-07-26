/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:40 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/26 15:49:54 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

t_cast_ray	*init_strcut_cast_ray(t_game *game)
{
	t_cast_ray	*ca_ray;

	ca_ray = malloc(sizeof(t_cast_ray));
	if (!ca_ray)
	{
		exit(1);
	}
	ca_ray->num_of_rays = 1920;
	ca_ray->dr = ((2 * PI) / ca_ray->num_of_rays) / ((float)360 / 90);
	ca_ray->ra = game->rot_pl - (ca_ray->dr * ca_ray->num_of_rays / 2);
	if (ca_ray->ra > 2 * PI)
		ca_ray->ra -= 2 * PI;
	if (ca_ray->ra < 0)
		ca_ray->ra += 2 * PI;
	ca_ray->rays = 0;
	game->pdx = cos(game->rot_pl) * 6;
	game->pdy = sin(game->rot_pl) * 6;
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

void	set_the_min_pos(t_game *game)
{
	if (game->cast_ray->dish < game->cast_ray->disv)
	{
		game->endpoint_x = game->cast_ray->hx;
		game->endpoint_y = game->cast_ray->hy;
		game->cast_ray->final_dis = game->cast_ray->dish;
	}
	else
	{
		game->endpoint_x = game->cast_ray->vx;
		game->endpoint_y = game->cast_ray->vy;
		game->cast_ray->final_dis = game->cast_ray->disv;
	}
}
