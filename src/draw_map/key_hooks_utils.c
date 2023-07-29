/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:19:17 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/29 19:52:02 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

// void	key_w(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
// {
// 	tmp_yp = map_draw->y_p + map_draw->pdy;
// 	tmp_xp = map_draw->x_p + map_draw->pdx;
// 	if (map_draw->rot_pl >= 0 && map_draw->rot_pl < (2 * M_PI) / 4)
// 	{
// 		tmp_xp += map_draw->h_sq / 4;
// 		tmp_yp += map_draw->h_sq / 4;
// 	}
// 	else if (map_draw->rot_pl > (2 * M_PI) / 4 && map_draw->rot_pl <= (2 * M_PI) / 2)
// 	{
// 		tmp_xp += map_draw->h_sq / 4;
// 		tmp_yp += map_draw->h_sq / 4;
// 	}
// 	else if (map_draw->rot_pl > (2 * M_PI) / 2 && map_draw->rot_pl <= -((2 * M_PI) / 4))
// 	{
// 		tmp_xp -= map_draw->h_sq / 4;
// 		tmp_yp -= map_draw->h_sq / 4;
// 	}
// 	else if (map_draw->rot_pl > -((2 * M_PI) / 4) && map_draw->rot_pl <= 2 * M_PI)
// 	{
// 		tmp_xp += map_draw->h_sq / 4;
// 		tmp_yp -= map_draw->h_sq / 4;
// 	}
// 	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
// 		&& tmp_xp <= map_draw->w)
// 	{
// 		// if (map[(tmp_yp + game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
// 		// 	&& (game->h - ((tmp_yp / game->h_sq) * game->h_sq) + 10 - game->h_sq > game->h
// 		// 		- tmp_yp))
// 		// 	return ;
// 		// if (map[(tmp_yp) / game->h_sq][(tmp_xp - game->w_sq) / game->w_sq] == '1'
// 		// 	&& (((tmp_xp / game->w_sq) * game->w_sq) + 10 > tmp_xp))
// 		// 	return ;
// 		// if (map[(tmp_yp - game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
// 		// 	&& ((tmp_yp / game->h_sq) * game->h_sq + 5 >= tmp_yp))
// 		// 	return ;
// 		// if (map[(tmp_yp) / game->h_sq][(tmp_xp + game->w_sq) / game->w_sq] == '1'
// 		// 	&& (game->w - ((tmp_xp / game->w_sq) * game->w_sq) + 10 - game->h_sq > game->w
// 		// 		- tmp_xp))
// 		// 	return ;
// 		if (map[(tmp_yp) / map_draw->h_sq] && map[(tmp_yp) / map_draw->h_sq][(tmp_xp) / map_draw->w_sq] != '1')
// 		{
// 			map_draw->x_p_move += map_draw->pdx;
// 			map_draw->y_p_move += map_draw->pdy;
// 		}
// 	}
// }

// void	key_s(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
// {
// 	tmp_yp = map_draw->y_p - map_draw->pdy;
// 	tmp_xp = map_draw->x_p - map_draw->pdx;
// 	// if (map[(tmp_yp + game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
// 	// 	&& (game->h - ((tmp_yp / game->h_sq) * game->h_sq) + 10 - game->h_sq > game->h
// 	// 		- tmp_yp))
// 	// 	return ;
// 	// if (map[(tmp_yp) / game->h_sq][(tmp_xp - game->h_sq) / game->h_sq] == '1'
// 	// 	&& (((tmp_xp / game->w_sq) * game->w_sq) + 10 > tmp_xp))
// 	// 	return ;
// 	// if (map[(tmp_yp - game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
// 	// 	&& ((tmp_yp / game->h_sq) * game->h_sq + 5 >= tmp_yp))
// 	// 	return ;
// 	// if (map[(tmp_yp) / game->h_sq][(tmp_xp + game->w_sq) / game->h_sq] == '1'
// 	// 	&& (width - ((tmp_xp / game->w_sq) * game->h_sq) + 10 - game->w_sq > game->w
// 	// 		- tmp_xp))
// 	// 	return ;
// 	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
// 		&& tmp_xp <= map_draw->w)
// 	{
// 		if (map[(tmp_yp) / map_draw->h_sq] && map[(tmp_yp) / map_draw->h_sq][(tmp_xp) / map_draw->w_sq] != '1')
// 		{
// 			map_draw->x_p_move -= map_draw->pdx;
// 			map_draw->y_p_move -= map_draw->pdy;
// 		}
// 	}
// }

// void	key_a(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
// {
// 	tmp_xp = map_draw->x_p + (map_draw->pdx * cos(-M_PI / 2) - map_draw->pdy
// 			* sin(-M_PI / 2));
// 	tmp_yp = map_draw->y_p + (map_draw->pdx * sin(-M_PI / 2) + map_draw->pdy
// 			* cos(-M_PI / 2));
// 	// if (map[(tmp_yp + game->h_sq) / game->h][(tmp_xp) / game->h] == '1'
// 	// 	&& (game->h - ((tmp_yp / game->h_sq) * game->h_sq) + 10 - game->h_sq > game->h
// 	// 		- tmp_yp))
// 	// 	return ;
// 	// if (map[(tmp_yp) / game->h_sq][(tmp_xp - game->w_sq) / game->w_sq] == '1'
// 	// 	&& (((tmp_xp / game->w_sq) * game->w_sq) + 10 > tmp_xp))
// 	// 	return ;
// 	// if (map[(tmp_yp - game->h_sq) / game->h_sq][(tmp_xp) / game->h_sq] == '1'
// 	// 	&& (((tmp_yp / game->h_sq) * game->h_sq) + 10 >= tmp_yp))
// 	// 	return ;
// 	// if (map[(tmp_yp) / game->h_sq][(tmp_xp + game->h_sq) / 50] == '1'
// 	// 	&& (game->w - ((tmp_xp / game->w_sq) * game->w_sq) + 10 - game->w_sq > game->w
// 	// 		- tmp_xp))
// 	// 	return ;
// 	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
// 		&& tmp_xp <= map_draw->w)
// 	{
// 		if (map[(tmp_yp) / map_draw->h_sq] && map[(tmp_yp) / map_draw->h_sq][(tmp_xp) / map_draw->w_sq] != '1')
// 		{
// 			map_draw->x_p_move += (map_draw->pdx * cos(-M_PI / 2)
// 					- map_draw->pdy * sin(-M_PI / 2));
// 			map_draw->y_p_move += (map_draw->pdx * sin(-M_PI / 2)
// 					+ map_draw->pdy * cos(-M_PI / 2));
// 		}
// 	}
// }

// void	key_d(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
// {
// 	tmp_xp = map_draw->x_p + (map_draw->pdx * cos(M_PI / 2) - map_draw->pdy
// 			* sin(M_PI / 2));
// 	tmp_yp = map_draw->y_p + (map_draw->pdx * sin(M_PI / 2) + map_draw->pdy
// 			* cos(M_PI / 2));
// 	// if (map[(tmp_yp + game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
// 	// 	&& (game->h - ((tmp_yp / game->h_sq) * game->h_sq) + 10 - game->h_sq > game->h
// 	// 		- tmp_yp))
// 	// 	return ;
// 	// if (map[(tmp_yp) / game->h_sq][(tmp_xp - game->h_sq) / 50] == '1'
// 	// 	&& (((tmp_xp / game->w_sq) * game->w_sq) + 10 > tmp_xp))
// 	// 	return ;
// 	// if (map[(tmp_yp - game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
// 	// 	&& (((tmp_yp / game->h_sq) * game->h_sq) + 10 >= tmp_yp))
// 	// 	return ;
// 	// if (map[(tmp_yp) / game->h_sq][(tmp_xp + game->w_sq) / 50] == '1'
// 	// 	&& (game->w - ((tmp_xp / game->w_sq) * game->h_sq) + 10 - game->h_sq > game->w
// 	// 		- tmp_xp))
// 	// 	return ;
// 	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
// 		&& tmp_xp <= map_draw->w)
// 	{
// 		if (map[(tmp_yp) / map_draw->h_sq] && map[(tmp_yp) / map_draw->h_sq][(tmp_xp) / map_draw->w_sq] != '1')
// 		{
// 			map_draw->x_p_move += (map_draw->pdx * cos(M_PI / 2)
// 					- map_draw->pdy * sin(M_PI / 2));
// 			map_draw->y_p_move += (map_draw->pdx * sin(M_PI / 2)
// 					+ map_draw->pdy * cos(M_PI / 2));
// 		}
// 	}
// }



void	key_w(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
{
	tmp_yp = map_draw->y_p + map_draw->pdy;
	tmp_xp = map_draw->x_p + map_draw->pdx;
	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
		&& tmp_xp <= map_draw->w)
	{
		// if (map[(tmp_yp + 2) / 10][(tmp_xp) / 10] == '1'
		// 	&& (map_draw->h - ((tmp_yp / 10) * 10) + 2 - 2 > map_draw->h
		// 		- tmp_yp))
		// 	return ;
		// if (map[(tmp_yp) / 10][(tmp_xp - 2) / 10] == '1'
		// 	&& (((tmp_xp / 10) * 10) + 2 > tmp_xp))
		// 	return ;
		// if (map[(tmp_yp - 2) / 10][(tmp_xp) / 10] == '1'
		// 	&& ((tmp_yp / 10) * 10 + 2 >= tmp_yp))
		// 	return ;
		// if (map[(tmp_yp) / 10][(tmp_xp + 10) / 10] == '1'
		// 	&& (map_draw->w - ((tmp_xp / 10) * 10) + 2 - 2 > map_draw->w
		// 		- tmp_xp))
		// 	return ;
		
		if (map[(tmp_yp) / 10][(tmp_xp) / 10] != '1')
		{
			map_draw->x_p_move += map_draw->pdx;
			map_draw->y_p_move += map_draw->pdy;
		}
	}
}

void	key_s(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
{
	tmp_yp = map_draw->y_p - map_draw->pdy;
	tmp_xp = map_draw->x_p - map_draw->pdx;
	// if (map[(tmp_yp + 2) / 10][(tmp_xp) / 10] == '1'
	// 	&& (map_draw->h - ((tmp_yp / 10) * 10) + 2 - 2 > map_draw->h
	// 		- tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / 10][(tmp_xp - 2) / 10] == '1'
	// 	&& (((tmp_xp / 10) * 10) + 2 > tmp_xp))
	// 	return ;
	// if (map[(tmp_yp - 2) / 10][(tmp_xp) / 10] == '1'
	// 	&& ((tmp_yp / 10) * 10 + 2 >= tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / 10][(tmp_xp + 10) / 10] == '1'
	// 	&& (map_draw->w - ((tmp_xp / 10) * 10) + 2 - 2 > map_draw->w
	// 		- tmp_xp))
	// 	return ;
	
	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
		&& tmp_xp <= map_draw->w)
	{
		if (map[(tmp_yp) / 10][(tmp_xp) / 10] != '1')
		{
			map_draw->x_p_move -= map_draw->pdx;
			map_draw->y_p_move -= map_draw->pdy;
		}
	}
}

void	key_a(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
{
	tmp_xp = map_draw->x_p + (map_draw->pdx * cos(-M_PI / 2) - map_draw->pdy
			* sin(-M_PI / 2));
	tmp_yp = map_draw->y_p + (map_draw->pdx * sin(-M_PI / 2) + map_draw->pdy
			* cos(-M_PI / 2));
	// if (map[(tmp_yp + 2) / 10][(tmp_xp) / 10] == '1'
	// 	&& (map_draw->h - ((tmp_yp / 10) * 10) + 2 - 2 > map_draw->h
	// 		- tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / 10][(tmp_xp - 10) / 10] == '1'
	// 	&& (((tmp_xp / 10) * 10) + 10 > tmp_xp))
	// 	return ;
	// if (map[(tmp_yp - 2) / 10][(tmp_xp) / 10] == '1'
	// 	&& (((tmp_yp / 10) * 10) + 10 >= tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / 10][(tmp_xp + 10) / 10] == '1'
	// 	&& (map_draw->w - ((tmp_xp / 10) * 10) + 2 - 2 > map_draw->w
	// 		- tmp_xp))
	// 	return ;
	
	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
		&& tmp_xp <= map_draw->w)
	{
		if (map[(tmp_yp) / 10][(tmp_xp) / 10] != '1')
		{
			map_draw->x_p_move += (map_draw->pdx * cos(-M_PI / 2)
					- map_draw->pdy * sin(-M_PI / 2));
			map_draw->y_p_move += (map_draw->pdx * sin(-M_PI / 2)
					+ map_draw->pdy * cos(-M_PI / 2));
		}
	}
}

void	key_d(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
{
	tmp_xp = map_draw->x_p + (map_draw->pdx * cos(M_PI / 2) - map_draw->pdy
			* sin(M_PI / 2));
	tmp_yp = map_draw->y_p + (map_draw->pdx * sin(M_PI / 2) + map_draw->pdy
			* cos(M_PI / 2));

	// if (map[(tmp_yp + 2) / 10][(tmp_xp) / 10] == '1'
	// 	&& (map_draw->h - ((tmp_yp / 10) * 10) + 2 - 2 > map_draw->h
	// 		- tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / 10][(tmp_xp - 2) / 10] == '1'
	// 	&& (((tmp_xp / 10) * 10) + 2 > tmp_xp))
	// 	return ;
	// if (map[(tmp_yp - 2) / 10][(tmp_xp) / 10] == '1'
	// 	&& (((tmp_yp / 10) * 10) + 10 >= tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / 10][(tmp_xp + 10) / 10] == '1'
	// 	&& (map_draw->w - ((tmp_xp / 10) * 10) + 10 - 10 > map_draw->w
	// 		- tmp_xp))
	// 	return ;
	
	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
		&& tmp_xp <= map_draw->w)
	{
		if (map[(tmp_yp) / 10][(tmp_xp) / 10] != '1')
		{
			map_draw->x_p_move += (map_draw->pdx * cos(M_PI / 2)
					- map_draw->pdy * sin(M_PI / 2));
			map_draw->y_p_move += (map_draw->pdx * sin(M_PI / 2)
					+ map_draw->pdy * cos(M_PI / 2));
		}
	}
}
