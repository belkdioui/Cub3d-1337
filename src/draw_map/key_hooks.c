/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/17 12:27:59 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	arrows_keys(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ARROW_UP)
	{
		if (mlx_cub->y_up != '1')
			mlx_cub->y_player -= 20;
	}
	else if (keycode == ARROW_DOWN)
	{
		if (mlx_cub->y_down != '1')
			mlx_cub->y_player += 20;
	}
	else if (keycode == ARROW_RIGHT)
	{
		if (mlx_cub->x_right != '1')
			mlx_cub->x_player += 20;
	}
	else if (keycode == ARROW_LEFT)
	{
		if (mlx_cub->x_left != '1')
			mlx_cub->x_player -= 20;
	}
	mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	drawing_map(mlx_cub->map, mlx_cub);
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win, \
			mlx_cub->data.img, 0, 0);
}

int	key_hock(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
		free(mlx_cub->mlx_ptr);
		exit(0);
	}
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN || \
		keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		arrows_keys(keycode, mlx_cub);
	return (0);
}
