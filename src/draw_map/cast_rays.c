/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:19:10 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/29 19:29:33 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	check_greater_or_less_in_part_horiz(t_map *map_draw, t_cast_ray *ca_ray)
{
	if (ca_ray->ra > PI)
	{
		ca_ray->ry = ((map_draw->y_p / map_draw->h_sq) * map_draw->h_sq) - 0.0001;
		ca_ray->rx = (map_draw->y_p - ca_ray->ry) * \
				ca_ray->atan + (float)map_draw->x_p;
		ca_ray->yo = -map_draw->h_sq;
		ca_ray->xo = -ca_ray->yo * ca_ray->atan;
	}
	if (ca_ray->ra < PI)
	{
		ca_ray->ry = ((map_draw->y_p / map_draw->h_sq) * map_draw->h_sq) + map_draw->h_sq;
		ca_ray->rx = (map_draw->y_p - ca_ray->ry) * \
			ca_ray->atan + (float)map_draw->x_p;
		ca_ray->yo = map_draw->h_sq;
		ca_ray->xo = -ca_ray->yo * ca_ray->atan;
	}
	if (ca_ray->ra == 0 || ca_ray->ra == (float)PI)
	{
		ca_ray->rx = (float)map_draw->x_p;
		ca_ray->ry = (float)map_draw->y_p;
		ca_ray->dof = map_draw->w / map_draw->h_sq;
	}
}

void	check_horiental(t_map *map_draw, t_cast_ray *ca_ray, char **map)
{
	ca_ray->dof = 0;
	ca_ray->atan = -1 / tan(ca_ray->ra);
	check_greater_or_less_in_part_horiz(map_draw, ca_ray);
	while (ca_ray->dof < map_draw->j)
	{
		ca_ray->mx = (int)(ca_ray->rx / map_draw->w_sq);
		ca_ray->my = (int)(ca_ray->ry / map_draw->h_sq);
		if (ca_ray->mx >= 0 && ca_ray->mx < map_draw->j \
			&& ca_ray->my >= 0 && ca_ray->my < map_draw->i && map[ca_ray->my][ca_ray->mx] == '1')
		{
			ca_ray->dof = map_draw->w / map_draw->w_sq;
			ca_ray->hx = ca_ray->rx;
			ca_ray->hy = ca_ray->ry;
			ca_ray->dish = calc_dist(map_draw->x_p, map_draw->y_p, \
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

void	check_greater_or_less_in_part_verti(t_map *map_draw, t_cast_ray *ca_ray)
{
	if (ca_ray->ra > (M_PI / 2) && ca_ray->ra < ((3 * M_PI) / 2))
	{
		ca_ray->rx = ((map_draw->x_p / map_draw->w_sq) * map_draw->w_sq) - 0.0001;
		ca_ray->ry = (map_draw->x_p - ca_ray->rx) * \
			ca_ray->ntan + (float)map_draw->y_p;
		ca_ray->xo = -map_draw->w_sq;
		ca_ray->yo = -ca_ray->xo * ca_ray->ntan;
	}
	if (ca_ray->ra < (M_PI / 2) || ca_ray->ra > ((3 * M_PI) / 2))
	{
		ca_ray->rx = ((map_draw->x_p / map_draw->w_sq) * map_draw->w_sq) + map_draw->w_sq;
		ca_ray->ry = (map_draw->x_p - ca_ray->rx) * \
			ca_ray->ntan + (float)map_draw->y_p;
		ca_ray->xo = map_draw->w_sq;
		ca_ray->yo = -ca_ray->xo * ca_ray->ntan;
	}
	if (ca_ray->ra == 0 || ca_ray->ra == (float)PI)
	{
		ca_ray->rx = (float)map_draw->x_p;
		ca_ray->ry = (float)map_draw->y_p;
		ca_ray->dof = map_draw->w / map_draw->w_sq;
	}
}

void	check_vertical(t_map *map_draw, t_cast_ray *ca_ray, char **map)
{
	ca_ray->dof = 0;
	ca_ray->ntan = -tan(ca_ray->ra);
	check_greater_or_less_in_part_verti(map_draw, ca_ray);
	while (ca_ray->dof < map_draw->j)
	{
		ca_ray->mx = (int)(ca_ray->rx / map_draw->w_sq);
		ca_ray->my = (int)(ca_ray->ry / map_draw->h_sq);
		if (ca_ray->mx >= 0 && ca_ray->mx < map_draw->j && ca_ray->my >= 0 && \
			ca_ray->my < map_draw->i && map[ca_ray->my][ca_ray->mx] == '1')
		{
			ca_ray->dof = map_draw->w / map_draw->w_sq;
			ca_ray->vx = ca_ray->rx;
			ca_ray->vy = ca_ray->ry;
			ca_ray->disv = calc_dist(map_draw->x_p, map_draw->y_p, \
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

void	draw_view(t_global *glob)
{
	float fish_eye = glob->rot_pl - glob->ra;
	if(fish_eye > 2 * PI)
		fish_eye -= 2 * PI;
	else if(fish_eye < 0)
		fish_eye += 2 * PI;
	glob->final_dis = (glob->final_dis * cos(fish_eye)) * 8;
	float lineH = (glob->h*72)/glob->final_dis;
	if(lineH > glob->h)
		lineH = glob->h;
	float	celling = glob->h/2 - lineH/2;
	float	floor = lineH + celling;
	float y = 0;
	while(y < lineH)
	{
		//0xFF00000
		my_mlx_pixel_put(&glob->data, glob->rays, celling + y, 0x000000);
		y++;
	}
	while(celling > 0)
	{
		my_mlx_pixel_put(&glob->data, glob->rays, celling, 0xb3cde0);
		celling--;
	}
	while(floor < glob->h)
	{
		my_mlx_pixel_put(&glob->data, glob->rays, floor, 0x011f4b);
		floor++;
	}
}

void	cast_rays(t_global *glob, t_map *map_draw, char **map)
{
	map_draw->cast_ray = init_strcut_cast_ray(map_draw);
	while (map_draw->cast_ray->rays < map_draw->cast_ray->num_of_rays)
	{
		map_draw->cast_ray->dish = 100000000;
		map_draw->cast_ray->disv = 100000000;
		check_horiental(map_draw, map_draw->cast_ray, map);
		check_vertical(map_draw, map_draw->cast_ray, map);
		set_the_min_pos(map_draw);
		draw_line(map_draw, map_draw->x_p, map_draw->y_p);
		glob->rot_pl = map_draw->rot_pl;
		glob->final_dis = map_draw->cast_ray->final_dis;
		glob->ra = map_draw->cast_ray->ra;
		glob->rays = map_draw->cast_ray->rays;
		glob->h = height;
		draw_view(glob);
		map_draw->cast_ray->ra += map_draw->cast_ray->dr;
		if (map_draw->cast_ray->ra > 2 * PI)
			map_draw->cast_ray->ra -= 2 * PI;
		if (map_draw->cast_ray->ra < 0)
			map_draw->cast_ray->ra += 2 * PI;
		map_draw->cast_ray->rays++;
	}
}
