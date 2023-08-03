/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:16:56 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/03 17:44:34 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	close_window(t_global *glob)
{
	mlx_destroy_image(glob->mlx_cub->mlx_ptr, glob->mlx_cub->data.img);
	mlx_destroy_image(glob->mlx_cub->mlx_ptr, glob->mlx_cub->data2.img);
	mlx_destroy_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win);
	free_data_textures(glob);
	free_all(glob);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_ele	*get_map(int ac, char **av, t_global *glob)
{
	char	**cnt_file;
	t_ele	*ele;

	cnt_file = ver_and_ret_map(ac, av);
	if (!cnt_file || !cnt_file[0])
	{
		ft_putstr_fd("error in the name\n", 2);
		exit(1);
	}
	ele = malloc(sizeof(t_ele));
	if (!ele)
		exit(1);
	if (!check_the_map(cnt_file, ele, glob))
	{
		ft_putstr_fd("error in the map\n", 2);
		exit(1);
	}
	free_db(cnt_file);
	return (ele);
}

void	check_size(t_global *glob, t_map *map_draw)
{
	if (map_draw->w_sq * map_draw->j > map_draw->w || map_draw->h_sq
		* map_draw->i > map_draw->h)
	{
		ft_putstr_fd("error\n", 2);
		free_ele(glob->ele);
		free(glob->map);
		free(glob);
		exit(1);
	}
}
