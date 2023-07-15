/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:33:58 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/15 15:40:02 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	protection(t_mlx *mlx_cub)
{
	free(mlx_cub->mlx_ptr);
	perror("");
	exit(1);
}

void	big_width_and_height(int *big_width, int *height, char **map)
{
	int	i;
	int	j;
	int	count_width;

	i = 0;
	*big_width = 0;
	*height = 0;
	i = search_beginning_the_map(map);
	while (map[i])
	{
		count_width = 0;
		j = 0;
		while (map[i][j] != '\n' && map[i][j++] != '\0')
			count_width++;
		if (*big_width < count_width)
			*big_width = count_width;
		(*height)++;
		i++;
	}
}

void	init(t_mlx *mlx_cub, t_data *data, char **map)
{
	mlx_cub->mlx_ptr = mlx_init();
	big_width_and_height(&mlx_cub->w, &mlx_cub->h, map);
	mlx_cub->h *= 50;
	mlx_cub->w *= 50;
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
