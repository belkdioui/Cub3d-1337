/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_cub3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:38:08 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/08/03 18:47:10 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	free_db(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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

int	len_of_longest_line(char **pre_map)
{
	int		i;
	size_t	len;
	int		check;

	i = 0;
	check = 0;
	len = 0;
	while (pre_map[i])
	{
		if (len <= ft_strlen(pre_map[i]))
		{
			check = i;
			len = ft_strlen(pre_map[i]);
		}
		i++;
	}
	if (!ft_strchr(pre_map[check], '\n'))
		len++;
	return (len);
}

int	search_and_ret_place(char *av)
{
	int	i;

	i = 0;
	while (av)
	{
		if (av[i] == '.')
			break ;
		i++;
	}
	return (i);
}
