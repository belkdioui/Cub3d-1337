/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_is_protected.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:49:25 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/16 01:03:05 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	top(int *copy, int y, char **map, int *protect)
{
	while (*copy >= 0)
	{
		if (map[*copy][y] == '1')
		{
			(*protect)++;
			break ;
		}
		if (map[*copy][y] != ' ' && map[*copy][y] != '\n')
			break ;
		if (*copy == 0)
			(*protect)++;
		(*copy)--;
	}
}

void	bottom(int *copy, int y, char **map, int *protect)
{
	int	num_lines;

	num_lines = cal_number_of_lines_map(map) - 1;
	while (*copy <= num_lines)
	{
		if (map[*copy][y] == '1')
		{
			(*protect)++;
			break ;
		}
		if (map[*copy][y] != ' ' && map[*copy][y] != '\n')
			break ;
		if (*copy == num_lines)
			(*protect)++;
		(*copy)++;
	}
}

void	left(int x, int *copy, char **map, int *protect)
{
	while (*copy >= 0)
	{
		if (map[x][*copy] == '1')
		{
			(*protect)++;
			break ;
		}
		if (map[x][*copy] != ' ' && map[x][*copy] != '\n')
			break ;
		if (*copy == 0)
			(*protect)++;
		(*copy)--;
	}
}

void	right(int x, int *copy, char **map, int *protect)
{
	int	len;

	len = 0;
	while (map[x][len] != '\n')
		len++;
	while (*copy <= len)
	{
		if (map[x][*copy] == '1')
		{
			(*protect)++;
			break ;
		}
		if (map[x][*copy] != ' ' && map[x][*copy] != '\n')
			break ;
		if (*copy == len)
			(*protect)++;
		(*copy)++;
	}
}

int	space_is_protected(char **map, int x, int y)
{
	int	copy;
	int	protect;

	protect = 0;
	copy = x;
	top(&copy, y, map, &protect);
	copy = x;
	bottom(&copy, y, map, &protect);
	copy = y;
	left(x, &copy, map, &protect);
	copy = y;
	right(x, &copy, map, &protect);
	if (protect == 4)
		return (1);
	return (0);
}
