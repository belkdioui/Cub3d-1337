/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/26 17:14:05 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


void	draw_after_event(t_mlx *mlx_cub, t_gloabl *global)
{
	mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	draw_game(global->game, global->ele->map);
	draw_game(global->mini_game, global->ele->map);

	/* i think in this part i want separt bonus and mandatory */
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win,
		global->game->data.img, 0, 0);
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win,\
		global->mini_game->data.img, 0, 0);
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

void	move_keys(int keycode, t_gloabl *glob)
{
	check_keys(keycode, glob->game, glob->ele->map);
	check_keys(keycode, glob->mini_game, glob->ele->map);
	draw_after_event(glob->mlx_cub, glob);
	// mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	// drawing_map(mlx_cub->ele->map, mlx_cub, &mlx_cub->data);
	// mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win,
	// 	mlx_cub->data.img, 0, 0);
	// mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win, mlx_cub->data2.img, 0, 0);
}

void	free_ele(t_ele *ele)
{
	free(ele->c);
	free(ele->f);
	free(ele->ea);
	free(ele->we);
	free(ele->no);
	free(ele->so);
	free_db(ele->map);
	free(ele);
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
	draw_after_event(glob->mlx_cub, glob);
}

int	key_hock(int keycode, t_gloabl *glob)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(glob->mlx_cub->mlx_ptr, glob->mlx_cub->data.img);
		mlx_destroy_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win);
		// free_ele(mlx_cub->ele);
		// free(mlx_cub->cast_ray);
		// free(mlx_cub);
		// system("leaks cub3D");
		exit(0);
	}
	else if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		// free(mlx_cub->cast_ray);
		move_keys(keycode, glob);
	}
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
	{
		// free(mlx_cub->cast_ray);
		rotation_player(keycode, glob->game, glob);
		rotation_player(keycode, glob->mini_game, glob);
	}
	return (0);
}
