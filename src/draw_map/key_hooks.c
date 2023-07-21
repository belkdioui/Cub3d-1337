/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/21 12:51:11 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	check_keys(int keycode, t_mlx *mlx_cub, int i, int j)
{
	int	tmp_xp = 0;
	int	tmp_yp = 0;

	if (keycode == ARROW_RIGHT)
	{
		mlx_cub->rot_pl += 0.1;
		if(mlx_cub->rot_pl >= M_PI*2)
			mlx_cub->rot_pl -= M_PI*2;
		mlx_cub->pdx =  cos(mlx_cub->rot_pl) * 50;
		mlx_cub->pdy =  sin(mlx_cub->rot_pl) * 50;
	}
	else if (keycode == ARROW_LEFT)
	{
		mlx_cub->rot_pl -= 0.1;
		if(mlx_cub->rot_pl < 0)
			mlx_cub->rot_pl += M_PI*2;
		mlx_cub->pdx =  cos(mlx_cub->rot_pl) * 50;
		mlx_cub->pdy =  sin(mlx_cub->rot_pl) * 50;
	}
	else if (keycode == W)
	{
		tmp_yp += mlx_cub->y_p + ((int)mlx_cub->pdy / 4);
		tmp_xp += mlx_cub->x_p + ((int)mlx_cub->pdx / 4);
		if (tmp_yp  >= 0 && tmp_yp  <= mlx_cub->h && tmp_xp >= 0 && tmp_xp <= mlx_cub->w)
		{
			if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp) / 50] != '1')
			{
				mlx_cub->x_p_move += ((int)mlx_cub->pdx / 4);
				mlx_cub->y_p_move += ((int)mlx_cub->pdy / 4);
			}
		}
	}
	else if (keycode == S)
	{
		tmp_yp = mlx_cub->y_p - ((int)mlx_cub->pdy / 4);
		tmp_xp = mlx_cub->x_p - ((int)mlx_cub->pdx / 4);
		if (tmp_yp >= 0 && tmp_yp  <= mlx_cub->h && tmp_xp >= 0 && tmp_xp <= mlx_cub->w)
		{
			if (mlx_cub->ele->map[(tmp_yp) / 50][(tmp_xp) / 50] != '1')
			{
				mlx_cub->x_p_move -= ((int)mlx_cub->pdx / 4);
				mlx_cub->y_p_move -= ((int)mlx_cub->pdy / 4);
			}
		}
	}
	else if (keycode == D)
	{
		if (mlx_cub->x_p + 10 <= mlx_cub->w)
			if (mlx_cub->ele->map[i / 50][(j + 10) / 50] != '1')
				mlx_cub->x_p_move += 10;
	}
	else if (keycode == A)
	{
		if (mlx_cub->x_p - 10 >= 0)
			if (mlx_cub->ele->map[i / 50][(j - 10) / 50] != '1')
				mlx_cub->x_p_move -= 10;
	}
}

void	move_keys(int keycode, t_mlx *mlx_cub)
{
	int	i;
	int	j;

	i = mlx_cub->y_p;
	j = mlx_cub->x_p;
	check_keys(keycode, mlx_cub, i, j);
	mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	drawing_map(mlx_cub->ele->map, mlx_cub);
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win, \
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

int	key_hock(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx_cub->mlx_ptr, mlx_cub->data.img);
		mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
		// free(mlx_cub->mlx_ptr);
		free_ele(mlx_cub->ele);
		free(mlx_cub);
		system("leaks cub3D");
		exit(0);
	}
	else if (keycode == W || keycode == S || \
		keycode == A || keycode == D || keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		move_keys(keycode, mlx_cub);
	return (0);
}
