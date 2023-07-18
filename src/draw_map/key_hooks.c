/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/18 11:50:38 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	check_keys(int keycode, t_mlx *mlx_cub, int i, int j)
{
	if (keycode == ARROW_UP)
	{
		if (mlx_cub->y_p - 10 >= 0)
			if (mlx_cub->ele->map[(i - 10) / 50][j / 50] != '1')
				mlx_cub->y_p_move -= 10;
	}
	else if (keycode == ARROW_DOWN)
	{
		if (mlx_cub->y_p + 10 <= mlx_cub->h)
			if (mlx_cub->ele->map[(i + 10) / 50][j / 50] != '1')
				mlx_cub->y_p_move += 10;
	}
	else if (keycode == ARROW_RIGHT)
	{
		if (mlx_cub->x_p + 10 <= mlx_cub->w)
			if (mlx_cub->ele->map[i / 50][(j + 10) / 50] != '1')
				mlx_cub->x_p_move += 10;
	}
	else if (keycode == ARROW_LEFT)
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

int	key_hock(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx_cub->mlx_ptr, mlx_cub->data.img);
		mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
		free(mlx_cub->mlx_ptr);
		/*hna mazal khas free dyal map ...*/
		free(mlx_cub);
		// system("leaks cub3D");
		exit(0);
	}
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN || \
		keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		move_keys(keycode, mlx_cub);
	return (0);
}
