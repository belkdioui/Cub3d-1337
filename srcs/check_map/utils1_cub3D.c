/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_cub3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:38:08 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/15 14:43:46 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_db(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

int	cal_number_of_lines_map(char **cnt_file)
{
	int	i;
	int	j;
	int	is_ele;
	int	num_of_ele;

	j = 0;
	num_of_ele = 0;
	i = 0;
	while (cnt_file[i])
	{
		num_of_ele = is_element(cnt_file[i], &is_ele);
		if (num_of_ele == 7)
			j++;
		i++;
	}
	return (j);
}

int	search_and_ret_place(char *av)
{
	int	i;

	i = 0;
	while (av)
	{
		if (av[i] == '.')
			break ;
		i++ ;
	}
	return (i);
}
