/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:33:58 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/29 19:03:18 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	calcul_width_height_the_map(char **map, t_map *mapp)
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
	mapp->i = i;
	mapp->j = j;
}



t_map	*init_map(t_global *glob, int check)
{
	t_map	*map;
	int		i;
	int		j;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(1);
	calcul_width_height_the_map(glob->ele->map, map);
	map->x_p_move = 0;
	map->y_p_move = 0;
	map->rot_pl = glob->rot_pl;
	map->w = width_map;
	map->h = height_map;
	map->w_sq = 10;
	map->h_sq = 10;
	map->data = glob->mlx_cub->data2;
	glob->data = glob->mlx_cub->data;
	return (map);
}

t_global	*init_global(t_global *glob, int ac, char **av)
{
	glob->mlx_cub = init_mlx();
	glob->ele = get_map(ac, av, glob);
	glob->map = init_map(glob, 1);
	return (glob);
}
