/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:33:58 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/27 16:49:14 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	calcul_width_height_the_map(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\n' && map[i][j] != '\0')
			j++;
		i++;
	}
	game->i = i;
	game->j = j;
}

void	init_game2(t_gloabl *glob, t_game *game)
{
	calcul_width_height_the_map(glob->ele->map, game);
	game->x_p_move = 0;
	game->y_p_move = 0;
	game->rot_pl = glob->rot_pl;
}

t_game	*init_game(t_gloabl *glob, int check)
{
	t_game	*game;
	int		i;
	int		j;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	init_game2(glob, game);
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
