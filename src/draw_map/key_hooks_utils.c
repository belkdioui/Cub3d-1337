/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:19:17 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/26 16:37:50 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	key_w(t_game *game, char **map, int tmp_xp, int tmp_yp)
{
	tmp_yp = game->y_p + game->pdy;
	tmp_xp = game->x_p + game->pdx;
	if (tmp_yp >= 0 && tmp_yp <= height && tmp_xp >= 0
		&& tmp_xp <= width)
	{
		// if (map[(tmp_yp + game->h_sq) / game->h_sq][(tmp_xp) / game->w_sq] == '1'
		// 	&& (height - ((tmp_yp / mlx_cub->h_sq) * mlx_cub->h_sq) + 10 - mlx_cub->h_sq > height
		// 		- tmp_yp))
		// 	return ;
		// if (map[(tmp_yp) / mlx_cub->h_sq][(tmp_xp - mlx_cub->w_sq) / mlx_cub->w_sq] == '1'
		// 	&& (((tmp_xp / mlx_cub->w_sq) * mlx_cub->w_sq) + 10 > tmp_xp))
		// 	return ;
		// if (map[(tmp_yp - mlx_cub->h_sq) / mlx_cub->h_sq][(tmp_xp) / mlx_cub->w_sq] == '1'
		// 	&& ((tmp_yp / mlx_cub->h_sq) * mlx_cub->h_sq + 5 >= tmp_yp))
		// 	return ;
		// if (map[(tmp_yp) / mlx_cub->h_sq][(tmp_xp + mlx_cub->w_sq) / mlx_cub->w_sq] == '1'
		// 	&& (width - ((tmp_xp / mlx_cub->w_sq) * mlx_cub->w_sq) + 10 - mlx_cub->h_sq > width
		// 		- tmp_xp))
		// 	return ;
		if (map[(tmp_yp) / game->h_sq][(tmp_xp) / game->w_sq] != '1')
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
	// if (mlx_cub->ele->map[(tmp_yp + mlx_cub->h_sq) / mlx_cub->h_sq][(tmp_xp) / mlx_cub->w_sq] == '1'
	// 	&& (height - ((tmp_yp / mlx_cub->h_sq) * mlx_cub->h_sq) + 10 - mlx_cub->h_sq > height
	// 		- tmp_yp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp) / mlx_cub->h_sq][(tmp_xp - mlx_cub->h_sq) / mlx_cub->h_sq] == '1'
	// 	&& (((tmp_xp / mlx_cub->w_sq) * mlx_cub->w_sq) + 10 > tmp_xp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp - mlx_cub->h_sq) / mlx_cub->h_sq][(tmp_xp) / mlx_cub->w_sq] == '1'
	// 	&& ((tmp_yp / mlx_cub->h_sq) * mlx_cub->h_sq + 5 >= tmp_yp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp) / mlx_cub->h_sq][(tmp_xp + mlx_cub->w_sq) / mlx_cub->h_sq] == '1'
	// 	&& (width - ((tmp_xp / mlx_cub->w_sq) * mlx_cub->h_sq) + 10 - mlx_cub->w_sq > width
	// 		- tmp_xp))
	// 	return ;
	if (tmp_yp >= 0 && tmp_yp <= game->h && tmp_xp >= 0
		&& tmp_xp <= game->w)
	{
		if (map[(tmp_yp) / game->h_sq][(tmp_xp) / game->w_sq] != '1')
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
	// if (mlx_cub->ele->map[(tmp_yp + 50) / 50][(tmp_xp) / 50] == '1'
	// 	&& (height - ((tmp_yp / 50) * 50) + 10 - 50 > height
	// 		- tmp_yp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp - 50) / 50] == '1'
	// 	&& (((tmp_xp / 50) * 50) + 10 > tmp_xp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp - 50) / 50][(tmp_xp) / 50] == '1'
	// 	&& (((tmp_yp / 50) * 50) + 10 >= tmp_yp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp + 50) / 50] == '1'
	// 	&& (width - ((tmp_xp / 50) * 50) + 10 - 50 > width
	// 		- tmp_xp))
	// 	return ;
	if (tmp_yp >= 0 && tmp_yp <= game->h && tmp_xp >= 0
		&& tmp_xp <= game->w)
	{
		if (map[(tmp_yp) / game->h_sq][(tmp_xp) / game->w_sq] != '1')
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
	// if (mlx_cub->ele->map[(tmp_yp + 50) / 50][(tmp_xp) / 50] == '1'
	// 	&& (height - ((tmp_yp / 50) * 50) + 10 - 50 > height
	// 		- tmp_yp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp - 50) / 50] == '1'
	// 	&& (((tmp_xp / 50) * 50) + 10 > tmp_xp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp - 50) / 50][(tmp_xp) / 50] == '1'
	// 	&& (((tmp_yp / 50) * 50) + 10 >= tmp_yp))
	// 	return ;
	// if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp + 50) / 50] == '1'
	// 	&& (width- ((tmp_xp / 50) * 50) + 10 - 50 > width
	// 		- tmp_xp))
	// 	return ;
	if (tmp_yp >= 0 && tmp_yp <= game->h && tmp_xp >= 0
		&& tmp_xp <= game->w)
	{
		if (map[(tmp_yp) / 50][(tmp_xp) / 50] != '1')
		{
			game->x_p_move += (game->pdx * cos(M_PI / 2)
					- game->pdy * sin(M_PI / 2));
			game->y_p_move += (game->pdx * sin(M_PI / 2)
					+ game->pdy * cos(M_PI / 2));
		}
	}
}
