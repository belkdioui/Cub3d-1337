/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:22:41 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/15 13:19:29 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	mlx_cub;
	t_data	data;
	char	**map;

	map = get_map(ac, av);
	if (map)
	{
		init(&mlx_cub, &data, map);
		window_coloring(&mlx_cub, &data);
		drawing_map(map, &mlx_cub, &data);
		mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win, \
			data.img, 0, 0);
		mlx_key_hook(mlx_cub.mlx_win, key_hock, &mlx_cub);
		mlx_hook(mlx_cub.mlx_win, ON_DESTROY, 0, close_window, &mlx_cub);
		mlx_loop(mlx_cub.mlx_ptr);
	}
	return (0);
}
