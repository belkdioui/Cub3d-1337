/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:33:58 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/27 12:43:00 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	protection(t_mlx *mlx_cub)
{
	free(mlx_cub->mlx_ptr);
	perror("");
	exit(1);
}

void	calcul_width_height_the_map(char **map, int *i, int *j)
{
	*i = 0;
	*j = 0;

	while (map[*i])
	{
		while (map[*i][*j] != '\n' && map[*i][*j] != '\0')
			(*j)++;
		(*i)++;
	}
}

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
	int	i;
	int	j;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	calcul_width_height_the_map(glob->ele->map, &i, &j);
	if (check == 0)
	{
		game->w = width;
		game->h = height;
		game->w_sq = 50;
		game->h_sq = 50;
		game->data = glob->mlx_cub->data;
	}
	else
	{
		game->w = width_map;
		game->h = height_map;
		game->w_sq = 10;
		game->h_sq = 10;
		game->data = glob->mlx_cub->data2;
	}
	game->x_p_move = 0;
	game->y_p_move = 0;
	game->rot_pl = glob->rot_pl;
	game->i = i;
	game->j = j;
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
