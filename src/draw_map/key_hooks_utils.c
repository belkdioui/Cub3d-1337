/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:19:17 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/25 18:42:31 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	key_w(t_mlx *mlx_cub, int tmp_xp, int tmp_yp)
{
	tmp_yp = mlx_cub->y_p + mlx_cub->pdy;
	tmp_xp = mlx_cub->x_p + mlx_cub->pdx;
	if (tmp_yp >= 0 && tmp_yp <= mlx_cub->h && tmp_xp >= 0
		&& tmp_xp <= mlx_cub->w)
	{
		if (mlx_cub->ele->map[(tmp_yp + 50) / 50][(tmp_xp) / 50] == '1'
			&& (mlx_cub->h - ((tmp_yp / 50) * 50) + 10 - 50 > mlx_cub->h
				- tmp_yp))
			return ;
		if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp - 50) / 50] == '1'
			&& (((tmp_xp / 50) * 50) + 10 > tmp_xp))
			return ;
		if (mlx_cub->ele->map[(tmp_yp - 50) / 50][(tmp_xp) / 50] == '1'
			&& ((tmp_yp / 50) * 50 + 5 >= tmp_yp))
			return ;
		if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp + 50) / 50] == '1'
			&& (mlx_cub->w - ((tmp_xp / 50) * 50) + 10 - 50 > mlx_cub->w
				- tmp_xp))
			return ;
		else if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp) / 50] != '1')
		{
			mlx_cub->x_p_move += mlx_cub->pdx;
			mlx_cub->y_p_move += mlx_cub->pdy;
		}
	}
}

void	key_s(t_mlx *mlx_cub, int tmp_xp, int tmp_yp)
{
	tmp_yp = mlx_cub->y_p - mlx_cub->pdy;
	tmp_xp = mlx_cub->x_p - mlx_cub->pdx;
	if (mlx_cub->ele->map[(tmp_yp + 50) / 50][(tmp_xp) / 50] == '1'
		&& (mlx_cub->h - ((tmp_yp / 50) * 50) + 10 - 50 > mlx_cub->h
			- tmp_yp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp - 50) / 50] == '1'
		&& (((tmp_xp / 50) * 50) + 10 > tmp_xp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp - 50) / 50][(tmp_xp) / 50] == '1'
		&& ((tmp_yp / 50) * 50 + 5 >= tmp_yp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp + 50) / 50] == '1'
		&& (mlx_cub->w - ((tmp_xp / 50) * 50) + 10 - 50 > mlx_cub->w
			- tmp_xp))
		return ;
	if (tmp_yp >= 0 && tmp_yp <= mlx_cub->h && tmp_xp >= 0
		&& tmp_xp <= mlx_cub->w)
	{
		if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp) / 50] != '1')
		{
			mlx_cub->x_p_move -= mlx_cub->pdx;
			mlx_cub->y_p_move -= mlx_cub->pdy;
		}
	}
}

void	key_a(t_mlx *mlx_cub, int tmp_xp, int tmp_yp)
{
	tmp_xp = mlx_cub->x_p + (mlx_cub->pdx * cos(-M_PI / 2) - mlx_cub->pdy
			* sin(-M_PI / 2));
	tmp_yp = mlx_cub->y_p + (mlx_cub->pdx * sin(-M_PI / 2) + mlx_cub->pdy
			* cos(-M_PI / 2));
	if (mlx_cub->ele->map[(tmp_yp + 50) / 50][(tmp_xp) / 50] == '1'
		&& (mlx_cub->h - ((tmp_yp / 50) * 50) + 10 - 50 > mlx_cub->h
			- tmp_yp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp - 50) / 50] == '1'
		&& (((tmp_xp / 50) * 50) + 10 > tmp_xp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp - 50) / 50][(tmp_xp) / 50] == '1'
		&& (((tmp_yp / 50) * 50) + 10 >= tmp_yp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp + 50) / 50] == '1'
		&& (mlx_cub->w - ((tmp_xp / 50) * 50) + 10 - 50 > mlx_cub->w
			- tmp_xp))
		return ;
	if (tmp_yp >= 0 && tmp_yp <= mlx_cub->h && tmp_xp >= 0
		&& tmp_xp <= mlx_cub->w)
	{
		if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp) / 50] != '1')
		{
			mlx_cub->x_p_move += (mlx_cub->pdx * cos(-M_PI / 2)
					- mlx_cub->pdy * sin(-M_PI / 2));
			mlx_cub->y_p_move += (mlx_cub->pdx * sin(-M_PI / 2)
					+ mlx_cub->pdy * cos(-M_PI / 2));
		}
	}
}

void	key_d(t_mlx *mlx_cub, int tmp_xp, int tmp_yp)
{
	tmp_xp = mlx_cub->x_p + (mlx_cub->pdx * cos(M_PI / 2) - mlx_cub->pdy
			* sin(M_PI / 2));
	tmp_yp = mlx_cub->y_p + (mlx_cub->pdx * sin(M_PI / 2) + mlx_cub->pdy
			* cos(M_PI / 2));
	if (mlx_cub->ele->map[(tmp_yp + 50) / 50][(tmp_xp) / 50] == '1'
		&& (mlx_cub->h - ((tmp_yp / 50) * 50) + 10 - 50 > mlx_cub->h
			- tmp_yp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp - 50) / 50] == '1'
		&& (((tmp_xp / 50) * 50) + 10 > tmp_xp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp - 50) / 50][(tmp_xp) / 50] == '1'
		&& (((tmp_yp / 50) * 50) + 10 >= tmp_yp))
		return ;
	if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp + 50) / 50] == '1'
		&& (mlx_cub->w - ((tmp_xp / 50) * 50) + 10 - 50 > mlx_cub->w
			- tmp_xp))
		return ;
	if (tmp_yp >= 0 && tmp_yp <= mlx_cub->h && tmp_xp >= 0
		&& tmp_xp <= mlx_cub->w)
	{
		if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp) / 50] != '1')
		{
			mlx_cub->x_p_move += (mlx_cub->pdx * cos(M_PI / 2)
					- mlx_cub->pdy * sin(M_PI / 2));
			mlx_cub->y_p_move += (mlx_cub->pdx * sin(M_PI / 2)
					+ mlx_cub->pdy * cos(M_PI / 2));
		}
	}
}
