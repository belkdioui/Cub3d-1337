/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_is_protected.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:49:25 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/14 10:48:24 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/cub3D.h"
#include "../cub3d.h"

void	top(int *copy, int y, char **map, int *protect)
{
	while (*copy >= 0)
	{
		if (map[*copy][y] == '1')
		{
			(*protect)++ ;
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
			(*protect)++ ;
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
			(*protect)++ ;
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

	len = ft_strlen(map[x]) - 1;
	while (*copy <= len)
	{
		if (map[x][*copy] == '1')
		{
			(*protect)++ ;
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
