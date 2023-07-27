/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:19:17 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/27 12:24:20 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	key_w(t_game *game, char **map, int tmp_xp, int tmp_yp)
{
	tmp_yp = game->y_p + game->pdy;
	tmp_xp = game->x_p + game->pdx;
	if (tmp_yp >= 0 && tmp_yp <= game->h && tmp_xp >= 0
		&& tmp_xp <= game->w)
	{
		// if (map[(tmp_yp + game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
		// 	&& (game->h - ((tmp_yp / game->h_sq) * game->h_sq) + 10 - game->h_sq > game->h
		// 		- tmp_yp))
		// 	return ;
		// if (map[(tmp_yp) / game->h_sq][(tmp_xp - game->w_sq) / game->w_sq] == '1'
		// 	&& (((tmp_xp / game->w_sq) * game->w_sq) + 10 > tmp_xp))
		// 	return ;
		// if (map[(tmp_yp - game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
		// 	&& ((tmp_yp / game->h_sq) * game->h_sq + 5 >= tmp_yp))
		// 	return ;
		// if (map[(tmp_yp) / game->h_sq][(tmp_xp + game->w_sq) / game->w_sq] == '1'
		// 	&& (game->w - ((tmp_xp / game->w_sq) * game->w_sq) + 10 - game->h_sq > game->w
		// 		- tmp_xp))
		// 	return ;
		if (map[(tmp_yp) / game->h_sq] && map[(tmp_yp) / game->h_sq][(tmp_xp) / game->w_sq] != '1')
		{
			game->x_p_move += game->pdx;
			game->y_p_move += game->pdy;
		}
	}
}

void	key_s(t_game *game, char **map, int tmp_xp, int tmp_yp)
{
	tmp_yp = game->y_p - game->pdy;
	tmp_xp = game->x_p - game->pdx;
	// if (map[(tmp_yp + game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
	// 	&& (game->h - ((tmp_yp / game->h_sq) * game->h_sq) + 10 - game->h_sq > game->h
	// 		- tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / game->h_sq][(tmp_xp - game->h_sq) / game->h_sq] == '1'
	// 	&& (((tmp_xp / game->w_sq) * game->w_sq) + 10 > tmp_xp))
	// 	return ;
	// if (map[(tmp_yp - game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
	// 	&& ((tmp_yp / game->h_sq) * game->h_sq + 5 >= tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / game->h_sq][(tmp_xp + game->w_sq) / game->h_sq] == '1'
	// 	&& (width - ((tmp_xp / game->w_sq) * game->h_sq) + 10 - game->w_sq > game->w
	// 		- tmp_xp))
	// 	return ;
	if (tmp_yp >= 0 && tmp_yp <= game->h && tmp_xp >= 0
		&& tmp_xp <= game->w)
	{
		if (map[(tmp_yp) / game->h_sq] && map[(tmp_yp) / game->h_sq][(tmp_xp) / game->w_sq] != '1')
		{
			game->x_p_move -= game->pdx;
			game->y_p_move -= game->pdy;
		}
	}
}

void	key_a(t_game *game, char **map, int tmp_xp, int tmp_yp)
{
	tmp_xp = game->x_p + (game->pdx * cos(-M_PI / 2) - game->pdy
			* sin(-M_PI / 2));
	tmp_yp = game->y_p + (game->pdx * sin(-M_PI / 2) + game->pdy
			* cos(-M_PI / 2));
	// if (map[(tmp_yp + game->h_sq) / game->h][(tmp_xp) / game->h] == '1'
	// 	&& (game->h - ((tmp_yp / game->h_sq) * game->h_sq) + 10 - game->h_sq > game->h
	// 		- tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / game->h_sq][(tmp_xp - game->w_sq) / game->w_sq] == '1'
	// 	&& (((tmp_xp / game->w_sq) * game->w_sq) + 10 > tmp_xp))
	// 	return ;
	// if (map[(tmp_yp - game->h_sq) / game->h_sq][(tmp_xp) / game->h_sq] == '1'
	// 	&& (((tmp_yp / game->h_sq) * game->h_sq) + 10 >= tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / game->h_sq][(tmp_xp + game->h_sq) / 50] == '1'
	// 	&& (game->w - ((tmp_xp / game->w_sq) * game->w_sq) + 10 - game->w_sq > game->w
	// 		- tmp_xp))
	// 	return ;
	if (tmp_yp >= 0 && tmp_yp <= game->h && tmp_xp >= 0
		&& tmp_xp <= game->w)
	{
		if (map[(tmp_yp) / game->h_sq] && map[(tmp_yp) / game->h_sq][(tmp_xp) / game->w_sq] != '1')
		{
			game->x_p_move += (game->pdx * cos(-M_PI / 2)
					- game->pdy * sin(-M_PI / 2));
			game->y_p_move += (game->pdx * sin(-M_PI / 2)
					+ game->pdy * cos(-M_PI / 2));
		}
	}
}

void	key_d(t_game *game, char **map, int tmp_xp, int tmp_yp)
{
	tmp_xp = game->x_p + (game->pdx * cos(M_PI / 2) - game->pdy
			* sin(M_PI / 2));
	tmp_yp = game->y_p + (game->pdx * sin(M_PI / 2) + game->pdy
			* cos(M_PI / 2));
	// if (map[(tmp_yp + game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
	// 	&& (game->h - ((tmp_yp / game->h_sq) * game->h_sq) + 10 - game->h_sq > game->h
	// 		- tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / game->h_sq][(tmp_xp - game->h_sq) / 50] == '1'
	// 	&& (((tmp_xp / game->w_sq) * game->w_sq) + 10 > tmp_xp))
	// 	return ;
	// if (map[(tmp_yp - game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
	// 	&& (((tmp_yp / game->h_sq) * game->h_sq) + 10 >= tmp_yp))
	// 	return ;
	// if (map[(tmp_yp) / game->h_sq][(tmp_xp + game->w_sq) / 50] == '1'
	// 	&& (game->w - ((tmp_xp / game->w_sq) * game->h_sq) + 10 - game->h_sq > game->w
	// 		- tmp_xp))
	// 	return ;
	if (tmp_yp >= 0 && tmp_yp <= game->h && tmp_xp >= 0
		&& tmp_xp <= game->w)
	{
		if (map[(tmp_yp) / game->h_sq] && map[(tmp_yp) / game->h_sq][(tmp_xp) / game->w_sq] != '1')
		{
			game->x_p_move += (game->pdx * cos(M_PI / 2)
					- game->pdy * sin(M_PI / 2));
			game->y_p_move += (game->pdx * sin(M_PI / 2)
					+ game->pdy * cos(M_PI / 2));
		}
	}
}
