/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:22:41 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/15 12:51:08 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hock(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
		free(mlx_cub->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	close_window(t_mlx *mlx_cub)
{
	mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	free(mlx_cub->mlx_ptr);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

