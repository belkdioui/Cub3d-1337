/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:33:58 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/13 16:36:56 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	protection(t_mlx *mlx_cub)
{
	free(mlx_cub->mlx_ptr);
	perror("");
	exit(1);
}

void	init(t_mlx *mlx_cub, t_data *data)
{
	mlx_cub->mlx_ptr = mlx_init();
	mlx_cub->h = 800;
	mlx_cub->w = 800;
	if (!mlx_cub->mlx_ptr)
	{
		perror("");
		exit(1);
	}
	mlx_cub->mlx_win = mlx_new_window(mlx_cub->mlx_ptr, mlx_cub->w, mlx_cub->h, \
		"cub3d");
	if (!mlx_cub->mlx_win)
		protection(mlx_cub);
	data->img = mlx_new_image(mlx_cub->mlx_ptr, mlx_cub->w, mlx_cub->h);
	if (!data->img)
		protection(mlx_cub);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	if (!data->addr)
		protection(mlx_cub);
}
