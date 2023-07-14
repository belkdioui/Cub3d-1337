/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:00:19 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/14 10:48:18 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/cub3D.h"
#include "../cub3d.h"

int	if_first_and_last(char **map, int i, int *j)
{
	while (map[i][*j])
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

int	if_bet_first_and_last(char **map, int i, int *j)
{
	while (map[i][*j] && map[i][*j] == ' ')
		(*j)++;
	if (map[i][*j] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
		return (0);
	while (map[i][*j])
	{
		if (map[i][*j] != '1' && map[i][*j] != ' ' && map[i][*j] != '\n'
				&& map[i][*j] != '0')
			return (0);
		if (map[i][*j] == ' ')
			if (!space_is_protected(map, i, *j))
				return (0);
		(*j)++;
	}
	return (1);
}

int	check_map(char **map)
{
	int	num_lines;
	int	i;
	int	j;

	i = 0;
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
			if (!if_bet_first_and_last(map, i, &j))
				return (0);
		i++;
	}
	return (1);
}

int	check_the_map(char **cnt_file, t_ele *ele)
{
	char	*check;

	check = is_element_and_saveit(cnt_file, 7, &ele->map);
	if (!check)
		return (0);
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
	if (!check_map(ele->map))
		return (0);
	return (1);
}
