/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:22:41 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/14 19:27:25 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hock(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
		free(mlx_cub->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	close_window(t_mlx *mlx_cub)
{
	mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	free(mlx_cub->mlx_ptr);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// int	main(int ac, char **av)
// {
// 	// t_data	data;
// 	// t_mlx	mlx_cub;
// 	// // char	*player;
// 	// // void	*image;

// 	// init(&mlx_cub, &data);
// 	// (void)ac;
// 	// (void)av;
// 	// mlx_cub.x = 0;
// 	// while (mlx_cub.x < mlx_cub.h)
// 	// {
// 	// 	mlx_cub.y = 0;
// 	// 	while (mlx_cub.y < mlx_cub.w)
// 	// 	{
// 	// 		my_mlx_pixel_put(&data, mlx_cub.x, mlx_cub.y, 0x00ffff);
// 	// 		(mlx_cub.y)++;
// 	// 	}
// 	// 	(mlx_cub.x)++;
// 	// }
// 	// mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win, data.img, 0, 0);
// 	// int		w = 50;
// 	// int		h = 50;
// 	// player = "./img/player_charachter.xpm";
// 	// image = mlx_xpm_file_to_image(mlx_cub.mlx_ptr, player, &w, &h);
// 	// mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win, image , 0, 0);
// 	// mlx_key_hook(mlx_cub.mlx_win, key_hock, &mlx_cub);
// 	// mlx_hook(mlx_cub.mlx_win, ON_DESTROY, 0, close_window, &mlx_cub);
// 	// mlx_loop(mlx_cub.mlx_ptr);
	
// 	t_mlx	mlx_cub;
// 	t_data	data;
// 	char	**mapp;
// 	int		i = 0;
// 	int		j = 0;
// 	double		x = 0;
// 	double		y = 0;
// 	int		iter_x = 0;
// 	int		iter_y = 0;
// 	int		iter_y_tmp = 0;

// 	mapp = map(ac, av);
// 	if (mapp)
// 	{
// 		init(&mlx_cub, &data, mapp);
// 		// while (mapp[i])
// 		// {
// 		// 	iter += 80;
// 		// 	while (y++ < iter && iter <= mlx_cub.h)
// 		// 	{
// 		// 		x = 0;
// 		// 		while (x++ < 80)
// 		// 			my_mlx_pixel_put(&data, x, y, 0x00ffff);
// 		// 	}
// 		// 	i++;
// 		// }

// 		//khdama 
// 		while (mapp[i])
// 		{
// 			j = 0;
// 			x = 0;
// 			iter_x = 0;
// 			iter_y_tmp += 80 * i;
// 			iter_y += 80;
// 			while (mapp[i][j])
// 			{
// 				iter_x += 80;
// 				while (x++ < iter_x && iter_x <= mlx_cub.w)
// 				{
// 					// if (i == 1)
// 					// 	y = 80;
// 					// if (i == 2)
// 					// 	y = 160;
// 					// if (i == 3)
// 					// 	y = 240;
// 					// if (i == 4)
// 					// 	y = 320;
// 					// if (i == 5)
// 					// 	y = 400;
// 					// else
// 						y = 0;
// 					while (y++ < iter_y && iter_y <= mlx_cub.h)
// 						my_mlx_pixel_put(&data, x, y, 0x00ffff);
// 				}
// 				j++;
// 			}
// 			i++;
// 		}
// 		mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win, data.img, 0, 0);
// 		mlx_key_hook(mlx_cub.mlx_win, key_hock, &mlx_cub);
// 		mlx_hook(mlx_cub.mlx_win, ON_DESTROY, 0, close_window, &mlx_cub);
// 		mlx_loop(mlx_cub.mlx_ptr);
// 	}
// 	return (0);
// }
