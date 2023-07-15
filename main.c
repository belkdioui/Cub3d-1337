/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:22:41 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/15 18:51:16 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	mlx_cub;
	char	**map;

	map = get_map(ac, av);
	if (map)
	{  
		init(&mlx_cub, map);
		mlx_cub.map = map;
		drawing_map(map, &mlx_cub);
		mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win, \
			mlx_cub.data.img, 0, 0);
		mlx_key_hook(mlx_cub.mlx_win, key_hock, &mlx_cub);
		mlx_hook(mlx_cub.mlx_win, ON_DESTROY, 0, close_window, &mlx_cub);
		mlx_loop(mlx_cub.mlx_ptr);
	}
	return (0);
}
