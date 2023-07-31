/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map-1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:48:04 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/29 13:48:21 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	check_rgb(char *rgb)
{
	char	**split_rgb;
	int		i;
	int		j;
	int		num_rgb;

	i = 0;
	split_rgb = ft_split(rgb, ',');
	while (split_rgb[i])
	{
		j = 0;
		while (split_rgb[i][j])
		{
			if (!ft_isdigit(split_rgb[i][j]) && split_rgb[i][j] != '\n')
				return (free_db(split_rgb), 0);
			j++;
		}
		num_rgb = ft_atoi(split_rgb[i]);
		if (!(num_rgb >= 0 && num_rgb <= 255))
			return (free_db(split_rgb), 0);
		i++;
	}
	if (i != 3)
		return (free_db(split_rgb), 0);
	return (free_db(split_rgb), 1);
}

int	check_img(char *textures)
{
	int	fd;

	textures = ft_strtrim(textures, "\n");
	fd = open(textures, O_RDONLY);
	if (fd == -1)
		return (free(textures), 0);
	return (free(textures), 1);
}

int	in_loop(char **map, int i, int *j, t_mlx *mlx_cub)
{
	if (map[i][*j] != '1' && map[i][*j] != ' ' && map[i][*j] != '\n'
			&& map[i][*j] != '0' && map[i][*j] != 'N' && map[i][*j] != 'S'
			&& map[i][*j] != 'E' && map[i][*j] != 'W')
		return (0);
	if (map[i][*j] == ' ')
		if (!space_is_protected(map, i, *j))
			return (0);
	if (map[i][*j] == 'N' || map[i][*j] == 'S' || map[i][*j] == 'E'
		|| map[i][*j] == 'W')
	{
		if (map[i][*j] == 'S')
			mlx_cub->rot_pl = (M_PI / 2) + 0.003;
		if (map[i][*j] == 'N')
			mlx_cub->rot_pl = ((3 * M_PI) / 2) + 0.003;
		if (map[i][*j] == 'E')
			mlx_cub->rot_pl = 0 + 0.003;
		if (map[i][*j] == 'W')
			mlx_cub->rot_pl = M_PI + 0.003;
		mlx_cub->num_of_player++;
	}
	return (1);
}

int	if_bet_first_and_last(char **map, int i, int *j, t_mlx *mlx_cub)
{
	int	last;

	last = 0;
	while (map[i][last] != '\n')
		last++;
	while (map[i][*j] && map[i][*j] == ' ')
		(*j)++;
	while (map[i][last] == '\n' || map[i][last] == ' ')
		last--;
	if (map[i][*j] != '1' || map[i][last] != '1')
		return (0);
	while (map[i][*j] != '\n')
	{
		if (!in_loop(map, i, j, mlx_cub))
			return (0);
		(*j)++;
	}
	return (1);
}
