/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/24 16:54:17 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	check_keys(int keycode, t_mlx *mlx_cub)
{
	int	tmp_xp;
	int	tmp_yp;

	if (keycode == W)
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
	else if (keycode == S)
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
	else if (keycode == A)
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
	else if (keycode == D)
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
}

void	move_keys(int keycode, t_mlx *mlx_cub)
{
	mlx_cub->x = 0;
	mlx_cub->y = -50;
	check_keys(keycode, mlx_cub);
	mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	drawing_map(mlx_cub->ele->map, mlx_cub);
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win,
		mlx_cub->data.img, 0, 0);
}

void	free_ele(t_ele *ele)
{
	free(ele->c);
	free(ele->f);
	free(ele->ea);
	free(ele->we);
	free(ele->no);
	free(ele->so);
	free_db(ele->map);
	free(ele);
}

void	rotation_player(int keycode, t_mlx *mlx_cub)
{
	mlx_cub->x = 0;
	mlx_cub->y = -50;
	if (keycode == ARROW_RIGHT)
	{
		mlx_cub->rot_pl += 0.1;
		if (mlx_cub->rot_pl >= M_PI * 2)
			mlx_cub->rot_pl -= M_PI * 2;
	}
	if (keycode == ARROW_LEFT)
	{
		mlx_cub->rot_pl -= 0.1;
		if (mlx_cub->rot_pl < 0)
			mlx_cub->rot_pl += M_PI * 2;
	}
	mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	drawing_map(mlx_cub->ele->map, mlx_cub);
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win,
		mlx_cub->data.img, 0, 0);
}

int	key_hock(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx_cub->mlx_ptr, mlx_cub->data.img);
		mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
		free_ele(mlx_cub->ele);
		free(mlx_cub->cast_ray);
		free(mlx_cub);
		system("leaks cub3D");
		exit(0);
	}
	else if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		free(mlx_cub->cast_ray);
		move_keys(keycode, mlx_cub);
	}
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
	{
		free(mlx_cub->cast_ray);
		rotation_player(keycode, mlx_cub);
	}
	return (0);
}
