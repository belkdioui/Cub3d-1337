/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:33:58 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/26 15:39:43 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	protection(t_mlx *mlx_cub)
{
	free(mlx_cub->mlx_ptr);
	perror("");
	exit(1);
}

// static void	width_and_height(int *width, int *height, char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j] != '\n' && map[i][j] != '\0')
// 			j++;
// 		*width = j;
// 		i++;
// 	}
// 	*height = i;
// }

void	calcul_width_height_the_square(t_game *game, char **map, int wi, int he)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (map[h])
	{
		while (map[h][w] != '\n' && map[h][w] != '\0')
			w++;
		h++;
	}
	game->h_sq = he / h;
	game->w_sq = wi / w;
}

// void	calcul_width_height_the_square(t_mlx *mlx_cub)
// {
// 	int	w;
// 	int	h;

// 	w = 0;
// 	h = 0;
// 	while (mlx_cub->ele->map[h])
// 	{
// 		while (mlx_cub->ele->map[h][w] != '\n' && mlx_cub->ele->map[h][w] != '\0')
// 			w++;
// 		h++;
// 	}
// 	mlx_cub->h_sq = height / h;
// 	mlx_cub->w_sq = width / w;
// 	mlx_cub->h_sq_map = height_map / h;
// 	mlx_cub->w_sq_map = width_map / w;
// }

t_mlx	*init_mlx()
{
	t_mlx	*mlx_cub;

	mlx_cub = malloc(sizeof(t_mlx));
	if (!mlx_cub)
		exit(1);
	mlx_cub->mlx_ptr = mlx_init();
	if (!mlx_cub->mlx_ptr)
	{
		perror("");
		exit(1);
	}
	mlx_cub->mlx_win = mlx_new_window(mlx_cub->mlx_ptr, width, height,
			"cub3d");
	if (!mlx_cub->mlx_win)
		protection(mlx_cub);
	/*initialization the first image*/
	mlx_cub->data.img = mlx_new_image(mlx_cub->mlx_ptr, width, height);
	if (!mlx_cub->data.img)
		protection(mlx_cub);
	mlx_cub->data.addr = mlx_get_data_addr(mlx_cub->data.img,
			&mlx_cub->data.bits_per_pixel, &mlx_cub->data.line_length,
			&mlx_cub->data.endian);
	if (!mlx_cub->data.addr)
		protection(mlx_cub);
	/* initialization the second image */
	mlx_cub->data2.img = mlx_new_image(mlx_cub->mlx_ptr, width_map, height_map);
	mlx_cub->data2.addr = mlx_get_data_addr(mlx_cub->data2.img, &mlx_cub->data2.bits_per_pixel,\
		 &mlx_cub->data2.line_length, &mlx_cub->data2.endian);
	if (!mlx_cub->data2.addr)
		protection(mlx_cub);
	return (mlx_cub);
}

t_game	*init_game(t_gloabl *glob, int check)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	if (check == 0)
	{
		game->w = width;
		game->h = height;
		calcul_width_height_the_square(game, glob->ele->map, width, height);
		game->data = glob->mlx_cub->data;
	}
	else
	{
		game->w = width_map;
		game->h = height_map;
		calcul_width_height_the_square(game, glob->ele->map, width_map, height_map);
		game->data = glob->mlx_cub->data2;
	}
	game->x_p_move = 0;
	game->y_p_move = 0;
	game->rot_pl = glob->rot_pl;
	return (game);
}

t_gloabl	*init_global(t_gloabl *glob, int ac, char **av)
{
	glob->mlx_cub = init_mlx();
	glob->ele = get_map(ac, av, glob);
	glob->game = init_game(glob, 0);
	glob->mini_game = init_game(glob, 1);
	return (glob);
}
