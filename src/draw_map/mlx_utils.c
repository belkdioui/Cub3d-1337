/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:16:56 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/26 16:06:37 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	close_window(t_mlx *mlx_cub)
{
	mlx_destroy_image(mlx_cub->mlx_ptr, mlx_cub->data.img);
	mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	free_ele(mlx_cub->ele);
	free(mlx_cub);
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
