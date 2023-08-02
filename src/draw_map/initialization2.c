/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:31:08 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/02 19:05:15 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	protection(t_mlx *mlx_cub)
{
	free(mlx_cub->mlx_ptr);
	perror("");
	exit(1);
}

void	init_images(t_mlx *mlx_cub)
{
	mlx_cub->data.img = mlx_new_image(mlx_cub->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx_cub->data.img)
		protection(mlx_cub);
	mlx_cub->data.addr = mlx_get_data_addr(mlx_cub->data.img,
			&mlx_cub->data.bits_per_pixel, &mlx_cub->data.line_length,
			&mlx_cub->data.endian);
	if (!mlx_cub->data.addr)
		protection(mlx_cub);
	mlx_cub->data2.img = mlx_new_image(mlx_cub->mlx_ptr, WIDTH_MAP, HEIGHT_MAP);
	mlx_cub->data2.addr = mlx_get_data_addr(mlx_cub->data2.img,
			&mlx_cub->data2.bits_per_pixel, &mlx_cub->data2.line_length,
			&mlx_cub->data2.endian);
	if (!mlx_cub->data2.addr)
		protection(mlx_cub);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx_cub;

	mlx_cub = malloc(sizeof(t_mlx));
	if (!mlx_cub)
		exit(1);
	mlx_cub->mlx_ptr = mlx_init();
	if (!mlx_cub->mlx_ptr)
		exit(1);
	mlx_cub->mlx_win = mlx_new_window(mlx_cub->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	if (!mlx_cub->mlx_win)
		protection(mlx_cub);
	init_images(mlx_cub);
	return (mlx_cub);
}
