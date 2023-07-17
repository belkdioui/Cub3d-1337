/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/17 12:06:40 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

int	main(int ac, char **av)
{
	char	**cnt_file;
	t_ele	*ele;
	t_mlx	mlx_cub;

	cnt_file = ver_and_ret_map(ac, av);
	if (!cnt_file)
		return (ft_putstr_fd("error in the name\n", 2), 0);
	ele = malloc(sizeof(t_ele));
	if (!check_the_map(cnt_file, ele))
		return (ft_putstr_fd("error in the map\n", 2), 0);
	init(&mlx_cub, ele->map);
	mlx_cub.map = ele->map;
	drawing_map(ele->map, &mlx_cub);
	mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win,
		mlx_cub.data.img, 0, 0);
	// mlx_key_hook(mlx_cub.mlx_win, key_hock, &mlx_cub);
	mlx_hook(mlx_cub.mlx_win, 2, 0, key_hock, &mlx_cub);
	mlx_hook(mlx_cub.mlx_win, ON_DESTROY, 0, close_window, &mlx_cub);
	mlx_loop(mlx_cub.mlx_ptr);
	printf("\n\n\n");
	system("leaks cub3D");
}
