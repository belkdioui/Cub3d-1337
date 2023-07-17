/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:16:56 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/17 12:27:52 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

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
