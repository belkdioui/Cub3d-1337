/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:22:41 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/13 17:08:55 by rrhnizar         ###   ########.fr       */
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

int	main(void)
{
	t_data	data;
	t_mlx	mlx_cub;

	init(&mlx_cub, &data);
	mlx_cub.x = 0;
	while (mlx_cub.x < mlx_cub.h)
	{
		mlx_cub.y = 0;
		while (mlx_cub.y < mlx_cub.w)
		{
			my_mlx_pixel_put(&data, mlx_cub.x, mlx_cub.y, 0x00ffff);
			(mlx_cub.y)++;
		}
		(mlx_cub.x)++;
	}
	mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win, data.img, 0, 0);
	mlx_key_hook(mlx_cub.mlx_win, key_hock, &mlx_cub);
	mlx_hook(mlx_cub.mlx_win, ON_DESTROY, 0, close_window, &mlx_cub);
	mlx_loop(mlx_cub.mlx_ptr);
	return (0);
}
