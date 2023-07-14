/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_element_and_return_it.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:51:19 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/14 10:48:28 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/cub3D.h"
#include "../cub3d.h"

char	*is_element_and_saveit(char **cnt_file, int which_ele, char ***save_map)
{
	int		i;
	int		num_of_ele;
	char	*save;
	int		is_ele;
	int		num_of_line_map;
	int		check;
	int		j;

	save = NULL;
	j = 0;
	i = 0;
	check = 0;
	is_ele = 0;
	if (which_ele == 7)
	{
		num_of_line_map = cal_number_of_lines_map(cnt_file);
		*save_map = malloc(sizeof(char *) * (num_of_line_map + 1));
		(*save_map)[num_of_line_map] = NULL;
	}
	while (cnt_file[i])
	{
		num_of_ele = is_element(cnt_file[i], &is_ele);
		if (!num_of_ele)
			return (0);
		if (num_of_ele == 7 && is_ele != 6)
			return (0);
		if (num_of_ele == 10 && is_ele == 6 && j != num_of_line_map
			&& check == 1)
			return (0);
		if (which_ele && num_of_ele == which_ele)
		{
			if (num_of_ele == 7)
			{
				check = 1;
				(*save_map)[j] = ret_element(cnt_file[i], num_of_ele);
				j++;
			}
			else
				save = ret_element(cnt_file[i], num_of_ele);
		}
		if (j == 0 && save)
			return (save);
		i++;
	}
	if (j == num_of_line_map)
		return ((*save_map)[1]);
	return (save);
}
