/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:19:17 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/02 19:05:50 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	key_w(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
{
	tmp_yp = map_draw->y_p + (int)map_draw->pdy;
	tmp_xp = map_draw->x_p + (int)map_draw->pdx;
	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
		&& tmp_xp <= map_draw->w)
	{
		if (map[(tmp_yp) / 10][(tmp_xp - 3) / 10] != '1' && map[(tmp_yp)
			/ 10][(tmp_xp + 3) / 10] != '1' && map[(tmp_yp + 3) / 10][(tmp_xp)
			/ 10] != '1' && map[(tmp_yp - 3) / 10][(tmp_xp) / 10] != '1')
		{
			map_draw->x_p_move += (int)map_draw->pdx;
			map_draw->y_p_move += (int)map_draw->pdy;
		}
	}
}

void	key_s(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
{
	tmp_yp = map_draw->y_p - (int)map_draw->pdy;
	tmp_xp = map_draw->x_p - (int)map_draw->pdx;
	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
		&& tmp_xp <= map_draw->w)
	{
		if (map[(tmp_yp) / 10][(tmp_xp - 3) / 10] != '1' && map[(tmp_yp)
			/ 10][(tmp_xp + 3) / 10] != '1' && map[(tmp_yp + 3) / 10][(tmp_xp)
			/ 10] != '1' && map[(tmp_yp - 3) / 10][(tmp_xp) / 10] != '1')
		{
			map_draw->x_p_move -= (int)map_draw->pdx;
			map_draw->y_p_move -= (int)map_draw->pdy;
		}
	}
}

void	key_a(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
{
	tmp_xp = map_draw->x_p + ((int)map_draw->pdx * cos(-M_PI / 2)
			- map_draw->pdy * sin(-M_PI / 2));
	tmp_yp = map_draw->y_p + ((int)map_draw->pdx * sin(-M_PI / 2)
			+ map_draw->pdy * cos(-M_PI / 2));
	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
		&& tmp_xp <= map_draw->w)
	{
		if (map[(tmp_yp) / 10][(tmp_xp - 3) / 10] != '1' && map[(tmp_yp)
			/ 10][(tmp_xp + 3) / 10] != '1' && map[(tmp_yp + 3) / 10][(tmp_xp)
			/ 10] != '1' && map[(tmp_yp - 3) / 10][(tmp_xp) / 10] != '1')
		{
			map_draw->x_p_move += ((int)map_draw->pdx * cos(-M_PI / 2)
					- map_draw->pdy * sin(-M_PI / 2));
			map_draw->y_p_move += ((int)map_draw->pdx * sin(-M_PI / 2)
					+ map_draw->pdy * cos(-M_PI / 2));
		}
	}
}

void	key_d(t_map *map_draw, char **map, int tmp_xp, int tmp_yp)
{
	tmp_xp = map_draw->x_p + ((int)map_draw->pdx * cos(M_PI / 2) - map_draw->pdy
			* sin(M_PI / 2));
	tmp_yp = map_draw->y_p + ((int)map_draw->pdx * sin(M_PI / 2) + map_draw->pdy
			* cos(M_PI / 2));
	if (tmp_yp >= 0 && tmp_yp <= map_draw->h && tmp_xp >= 0
		&& tmp_xp <= map_draw->w)
	{
		if (map[(tmp_yp) / 10][(tmp_xp - 3) / 10] != '1' && map[(tmp_yp)
			/ 10][(tmp_xp + 3) / 10] != '1' && map[(tmp_yp + 3) / 10][(tmp_xp)
			/ 10] != '1' && map[(tmp_yp - 3) / 10][(tmp_xp) / 10] != '1')
		{
			map_draw->x_p_move += ((int)map_draw->pdx * cos(M_PI / 2)
					- map_draw->pdy * sin(M_PI / 2));
			map_draw->y_p_move += ((int)map_draw->pdx * sin(M_PI / 2)
					+ map_draw->pdy * cos(M_PI / 2));
		}
	}
}
