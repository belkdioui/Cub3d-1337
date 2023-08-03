/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/03 17:44:22 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	draw_after_event(t_mlx *mlx_cub, t_global *global)
{
	mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	draw(global);
}

void	check_keys(int keycode, t_map *map_draw, char **map)
{
	if (keycode == W)
		key_w(map_draw, map, 0, 0);
	else if (keycode == S)
		key_s(map_draw, map, 0, 0);
	else if (keycode == A)
		key_a(map_draw, map, 0, 0);
	else if (keycode == D)
		key_d(map_draw, map, 0, 0);
}

void	rotation_player(int keycode, t_map *map_draw, t_global *glob)
{
	if (keycode == ARROW_RIGHT)
	{
		map_draw->rot_pl += 0.08;
		if (map_draw->rot_pl >= M_PI * 2)
			map_draw->rot_pl -= M_PI * 2;
	}
	if (keycode == ARROW_LEFT)
	{
		map_draw->rot_pl -= 0.08;
		if (map_draw->rot_pl < 0)
			map_draw->rot_pl += M_PI * 2;
	}
}

int	key_hock(int keycode, t_global *glob)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(glob->mlx_cub->mlx_ptr, glob->mlx_cub->data.img);
		mlx_destroy_image(glob->mlx_cub->mlx_ptr, glob->mlx_cub->data2.img);
		mlx_destroy_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win);
		free_data_textures(glob);
		free_all(glob);
		exit(0);
	}
	else if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		free(glob->map->cast_ray);
		check_keys(keycode, glob->map, glob->ele->map);
	}
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
	{
		free(glob->map->cast_ray);
		rotation_player(keycode, glob->map, glob);
	}
	else
		return (0);
	draw_after_event(glob->mlx_cub, glob);
	return (0);
}
