/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/24 12:47:54 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

t_ele	*get_map(int ac, char **av, t_mlx *mlx_cub)
{
	char	**cnt_file;
	t_ele	*ele;

	cnt_file = ver_and_ret_map(ac, av);
	if (!cnt_file)
	{
		ft_putstr_fd("error in the name\n", 2);
		exit(1);
	}
	ele = malloc(sizeof(t_ele));
	if (!ele)
		exit(1);
	if (!check_the_map(cnt_file, ele, mlx_cub))
	{
		ft_putstr_fd("error in the map\n", 2);
		exit(1);
	}
	free_db(cnt_file);
	return (ele);
}

void	draw_map(t_mlx *mlx_cub, t_ele *ele)
{
	// t_player	*player;

	// player = malloc(sizeof(t_player));
	// if (!player)
	// {
	// 	free(mlx_cub);
	// 	exit(1);
	// }
	init(mlx_cub, ele->map);
	drawing_map(ele->map, mlx_cub);
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win,
		mlx_cub->data.img, 0, 0);
	mlx_hook(mlx_cub->mlx_win, 2, 0, key_hock, mlx_cub);
	mlx_hook(mlx_cub->mlx_win, ON_DESTROY, 0, close_window, mlx_cub);
	mlx_loop(mlx_cub->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx_cub;

	mlx_cub = malloc(sizeof(t_mlx));
	if (!mlx_cub)
		exit(1);
	mlx_cub->ele = get_map(ac, av, mlx_cub);
	draw_map(mlx_cub, mlx_cub->ele);
	return (1);
}
