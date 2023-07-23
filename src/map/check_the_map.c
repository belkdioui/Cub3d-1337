/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:00:19 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/23 13:28:20 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	if_first_and_last(char **map, int i, int *j)
{
	while (map[i][*j] != '\n')
	{
		if (map[i][*j] != '1' && map[i][*j] != ' ' && map[i][*j] != '\n')
			return (0);
		if (map[i][*j] == ' ')
			if (!space_is_protected(map, i, *j))
				return (0);
		(*j)++;
	}
	return (1);
}

int	if_bet_first_and_last(char **map, int i, int *j,
	int *player, t_mlx *mlx_cub)
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
				mlx_cub->rot_pl = (M_PI / 2) - 0000.3;
			if (map[i][*j] == 'N')
				mlx_cub->rot_pl = ((3 * M_PI) / 2) - 000.3;
			if (map[i][*j] == 'E')
				mlx_cub->rot_pl = 0000.3;
			if (map[i][*j] == 'W')
				mlx_cub->rot_pl = M_PI - 0000.3;
			(*player)++;
		}
		(*j)++;
	}
	return (1);
}

int	check_map(char **map, t_mlx *mlx_cub)
{
	int	num_lines;
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	num_lines = cal_number_of_lines_map(map) - 1;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == num_lines)
		{
			if (!if_first_and_last(map, i, &j))
				return (0);
		}
		else
			if (!if_bet_first_and_last(map, i, &j, &player, mlx_cub))
				return (0);
		i++;
	}
	if (player != 1)
		return (0);
	return (1);
}

void	convert_the_map_to_rect(char ***new_map, char **pre_map)
{
	int		i;
	int		len;
	int		lines;
	int		j;
	int		diff;

	i = 0;
	len = len_of_longest_line(pre_map);
	lines = cal_number_of_lines_map(pre_map);
	*new_map = malloc(sizeof(char *) * (lines + 1));
	(*new_map)[lines] = NULL;
	while (pre_map[i])
	{
		j = 0;
		(*new_map)[i] = malloc(sizeof(char) * len + 1);
		(*new_map)[i][len] = '\0';
		while (pre_map[i][j] != '\n' && pre_map[i][j] != '\0')
		{
			(*new_map)[i][j] = pre_map[i][j];
			j++;
		}
		diff = len - j - 1;
		while (diff)
		{
			(*new_map)[i][j] = ' ';
			diff--;
			j++;
		}
		if (!diff)
			(*new_map)[i][j] = '\n';
		i++;
	}
	free_db(pre_map);
}

int	check_the_map(char **cnt_file, t_ele *ele, t_mlx *mlx_cub)
{
	char	*check;
	char	**map;

	check = is_element_and_saveit(cnt_file, 7, &map);
	if (!check)
		return (0);
	convert_the_map_to_rect(&ele->map, map);
	ele->no = is_element_and_saveit(cnt_file, 1, NULL);
	ele->so = is_element_and_saveit(cnt_file, 2, NULL);
	ele->we = is_element_and_saveit(cnt_file, 3, NULL);
	ele->ea = is_element_and_saveit(cnt_file, 4, NULL);
	ele->f = is_element_and_saveit(cnt_file, 5, NULL);
	ele->c = is_element_and_saveit(cnt_file, 6, NULL);
	if (!check_rgb(ele->f) || !check_rgb(ele->c))
		return (0);
	if (!check_img(ele->ea) || !check_img(ele->no) || !check_img(ele->so)
		|| !check_img(ele->we))
		return (0);
	if (!check_map(ele->map, mlx_cub))
		return (0);
	return (1);
}
