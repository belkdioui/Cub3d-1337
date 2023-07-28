/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/28 16:36:14 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	draw_after_event(t_mlx *mlx_cub, t_gloabl *global)
{
	mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	draw(global);
}

void	check_keys(int keycode, t_game *game, char **map)
{
	if (keycode == W)
		key_w(game, map, 0, 0);
	else if (keycode == S)
		key_s(game, map, 0, 0);
	else if (keycode == A)
		key_a(game, map, 0, 0);
	else if (keycode == D)
		key_d(game, map, 0, 0);
}

void	rotation_player(int keycode, t_game *game, t_gloabl *glob)
{
	if (keycode == ARROW_RIGHT)
	{
		game->rot_pl += 0.1;
		if (game->rot_pl >= M_PI * 2)
			game->rot_pl -= M_PI * 2;
	}
	if (keycode == ARROW_LEFT)
	{
		game->rot_pl -= 0.1;
		if (game->rot_pl < 0)
			game->rot_pl += M_PI * 2;
	}
}

int	key_hock(int keycode, t_gloabl *glob)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(glob->mlx_cub->mlx_ptr, glob->mlx_cub->data.img);
		mlx_destroy_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win);
		free_all(glob);
		system("leaks cub3D");
		exit(0);
	}
	else if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		free(glob->game->cast_ray);
		free(glob->mini_game->cast_ray);
		// glob->game->cast_ray = NULL;
		// glob->mini_game->cast_ray = NULL;
		check_keys(keycode, glob->game, glob->ele->map);
		check_keys(keycode, glob->mini_game, glob->ele->map);
	}
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
	{
		free(glob->game->cast_ray);
		free(glob->mini_game->cast_ray);
		// glob->game->cast_ray = NULL;
		// glob->mini_game->cast_ray = NULL;
		rotation_player(keycode, glob->game, glob);
		rotation_player(keycode, glob->mini_game, glob);
	}
	draw_after_event(glob->mlx_cub, glob);
	return (0);
}
