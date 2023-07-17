/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:16:56 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/17 12:05:06 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

// int	key_hock(int keycode, t_mlx *mlx_cub)
// {
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
// 		free(mlx_cub->mlx_ptr);
// 		exit(0);
// 	}
// 	return (0);
// }

int	close_window(t_mlx *mlx_cub)
{
	mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	free(mlx_cub->mlx_ptr);
	free_db(mlx_cub->map);
	printf("\n\n\n");
		system("leaks cub3D");
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
