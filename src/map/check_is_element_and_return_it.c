/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_element_and_return_it.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:51:19 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/30 10:13:28 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

char	**allocate_save_map(char **cnt_file)
{
	int		num_of_line_map;
	char	**save_map;

	num_of_line_map = cal_number_of_lines_map(cnt_file);
	save_map = malloc(sizeof(char *) * (num_of_line_map + 1));
	save_map[num_of_line_map] = NULL;
	return (save_map);
}

int	check_some_error(char **cnt_file, t_vars *vars)
{
	int	num_of_ele;

	num_of_ele = 0;
	num_of_ele = is_element(cnt_file[vars->i], &vars->is_ele);
	if (!num_of_ele)
		return (0);
	if (num_of_ele == 7 && vars->is_ele != 6)
		return (0);
	if (num_of_ele == 10 && vars->is_ele == 6
		&& vars->j != cal_number_of_lines_map(cnt_file) && vars->check == 1)
		return (0);
	return (num_of_ele);
}

char	*boucle_in_map(t_vars *vars, char **cnt_file,
	int which_ele, char ***save_map)
{
	char	*save;
	int		num_of_ele;

	num_of_ele = check_some_error(cnt_file, vars);
	if (!num_of_ele)
		return (0);
	if (which_ele && num_of_ele == which_ele)
	{
		if (num_of_ele == 7)
		{
			vars->check = 1;
			(*save_map)[vars->j] = ret_element(cnt_file[vars->i], num_of_ele);
			vars->j++;
		}
		else
			save = ret_element(cnt_file[vars->i], num_of_ele);
	}
	if (vars->j == 0 && save)
		return (save);
	return ((char *) 1);
}

char	*is_element_and_saveit(char **cnt_file, int which_ele, char ***save_map)
{
	t_vars	*vars;
	char	*save;

	vars = malloc(sizeof(t_vars));
	vars->is_ele = 0;
	vars->check = 0;
	save = NULL;
	vars->j = 0;
	vars->i = 0;
	if (which_ele == 7)
		*save_map = allocate_save_map(cnt_file);
	while (cnt_file[vars->i])
	{
		save = boucle_in_map(vars, cnt_file, which_ele, save_map);
		if (!save)
			return (free(vars), NULL);
		vars->i++;
	}
	if (vars->j == cal_number_of_lines_map(cnt_file))
		return (free(vars), (*save_map)[1]);
	return (free(vars), save);
}
