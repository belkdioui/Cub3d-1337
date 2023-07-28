/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:19:10 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/28 18:58:46 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	check_greater_or_less_in_part_horiz(t_game *game, t_cast_ray *ca_ray)
{
	if (ca_ray->ra > PI)
	{
		ca_ray->ry = ((game->y_p / game->h_sq) * game->h_sq) - 0.0001;
		ca_ray->rx = (game->y_p - ca_ray->ry) * \
				ca_ray->atan + (float)game->x_p;
		ca_ray->yo = -game->h_sq;
		ca_ray->xo = -ca_ray->yo * ca_ray->atan;
	}
	if (ca_ray->ra < PI)
	{
		ca_ray->ry = ((game->y_p / game->h_sq) * game->h_sq) + game->h_sq;
		ca_ray->rx = (game->y_p - ca_ray->ry) * \
			ca_ray->atan + (float)game->x_p;
		ca_ray->yo = game->h_sq;
		ca_ray->xo = -ca_ray->yo * ca_ray->atan;
	}
	if (ca_ray->ra == 0 || ca_ray->ra == (float)PI)
	{
		ca_ray->rx = (float)game->x_p;
		ca_ray->ry = (float)game->y_p;
		ca_ray->dof = game->w / game->h_sq;
	}
}

void	check_horiental(t_game *game, t_cast_ray *ca_ray, char **map)
{
	ca_ray->dof = 0;
	ca_ray->atan = -1 / tan(ca_ray->ra);
	check_greater_or_less_in_part_horiz(game, ca_ray);
	while (ca_ray->dof < game->j)
	{
		ca_ray->mx = (int)(ca_ray->rx / game->w_sq);
		ca_ray->my = (int)(ca_ray->ry / game->h_sq);
		if (ca_ray->mx >= 0 && ca_ray->mx < game->j \
			&& ca_ray->my >= 0 && ca_ray->my < game->i && map[ca_ray->my][ca_ray->mx] == '1')
		{
			ca_ray->dof = game->w / game->w_sq;
			ca_ray->hx = ca_ray->rx;
			ca_ray->hy = ca_ray->ry;
			ca_ray->dish = calc_dist(game->x_p, game->y_p, \
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

void	check_greater_or_less_in_part_verti(t_game *game, t_cast_ray *ca_ray)
{
	if (ca_ray->ra > (M_PI / 2) && ca_ray->ra < ((3 * M_PI) / 2))
	{
		ca_ray->rx = ((game->x_p / game->w_sq) * game->w_sq) - 0.0001;
		ca_ray->ry = (game->x_p - ca_ray->rx) * \
			ca_ray->ntan + (float)game->y_p;
		ca_ray->xo = -game->w_sq;
		ca_ray->yo = -ca_ray->xo * ca_ray->ntan;
	}
	if (ca_ray->ra < (M_PI / 2) || ca_ray->ra > ((3 * M_PI) / 2))
	{
		ca_ray->rx = ((game->x_p / game->w_sq) * game->w_sq) + game->w_sq;
		ca_ray->ry = (game->x_p - ca_ray->rx) * \
			ca_ray->ntan + (float)game->y_p;
		ca_ray->xo = game->w_sq;
		ca_ray->yo = -ca_ray->xo * ca_ray->ntan;
	}
	if (ca_ray->ra == 0 || ca_ray->ra == (float)PI)
	{
		ca_ray->rx = (float)game->x_p;
		ca_ray->ry = (float)game->y_p;
		ca_ray->dof = game->w / game->w_sq;
	}
}

void	check_vertical(t_game *game, t_cast_ray *ca_ray, char **map)
{
	ca_ray->dof = 0;
	ca_ray->ntan = -tan(ca_ray->ra);
	check_greater_or_less_in_part_verti(game, ca_ray);
	while (ca_ray->dof < game->j)
	{
		ca_ray->mx = (int)(ca_ray->rx / game->w_sq);
		ca_ray->my = (int)(ca_ray->ry / game->h_sq);
		if (ca_ray->mx >= 0 && ca_ray->mx < game->j && ca_ray->my >= 0 && \
			ca_ray->my < game->i && map[ca_ray->my][ca_ray->mx] == '1')
		{
			ca_ray->dof = game->w / game->w_sq;
			ca_ray->vx = ca_ray->rx;
			ca_ray->vy = ca_ray->ry;
			ca_ray->disv = calc_dist(game->x_p, game->y_p, \
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

void	cast_rays(t_game *game, char **map, int check)
{
	game->cast_ray = init_strcut_cast_ray(game, check);
	while (game->cast_ray->rays < game->cast_ray->num_of_rays)
	{
		game->cast_ray->dish = 100000000;
		game->cast_ray->disv = 100000000;
		check_horiental(game, game->cast_ray, map);
		check_vertical(game, game->cast_ray, map);
		set_the_min_pos(game);
		draw_line(game, game->x_p, game->y_p, check);

		// if (check == 0)
		// {
		// 	float fish_eye = game->rot_pl - game->cast_ray->ra;
		// 	if(fish_eye > 2 * PI)
		// 		fish_eye -= 2 * PI;
		// 	else if(fish_eye < 0)
		// 		fish_eye += 2 * PI;
		// 	game->cast_ray->final_dis = game->cast_ray->final_dis * cos(fish_eye);
		// 	float lineH = (game->h*72)/game->cast_ray->final_dis;
		// 	if(lineH > game->h)
		// 		lineH = game->h;
		// 	float	celling = game->h/2 - lineH/2;
		// 	float	floor = lineH + celling;
		// 	// printf("%d   %f   %f\n", game->h, lineH, celling);
		// 	float y = 0;
		// 	while(y < lineH)
		// 	{
		// 		my_mlx_pixel_put(&game->data, game->cast_ray->rays, celling + y, 0xFF00000);
		// 		y++;
		// 	}
		// 	while(celling > 0)
		// 	{
		// 		my_mlx_pixel_put(&game->data, game->cast_ray->rays, celling, 0xb3cde0);
		// 		celling--;
		// 	}
		// 	while(floor < game->h)
		// 	{
		// 		my_mlx_pixel_put(&game->data, game->cast_ray->rays, floor, 0x011f4b);
		// 		floor++;
		// 	}
		// }

		
		game->cast_ray->ra += game->cast_ray->dr;
		if (game->cast_ray->ra > 2 * PI)
			game->cast_ray->ra -= 2 * PI;
		if (game->cast_ray->ra < 0)
			game->cast_ray->ra += 2 * PI;
		game->cast_ray->rays++;
	}
}
