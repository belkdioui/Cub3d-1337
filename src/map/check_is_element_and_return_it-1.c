/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_element_and_return_it-1.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:56:11 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/08/03 09:32:38 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	get_i_and_j_for_substr(char *line, int *i, int *j)
{
	while (line[*i] == ' ')
		(*i)++;
	*j = *i;
	while (line[*i] != '\n' && line[*i] != ' ')
		(*i)++;
}

char	*ret_element(char *line, int num_of_ele)
{
	int		i;
	char	*save_ele;
	int		j;

	i = 0;
	j = 0;
	save_ele = NULL;
	while (line[i] == ' ')
		i++;
	if (num_of_ele >= 1 && num_of_ele <= 4)
	{
		i += 3;
		get_i_and_j_for_substr(line, &i, &j);
		save_ele = ft_substr(line, j, i - j);
	}
	else if (num_of_ele == 5 || num_of_ele == 6)
	{
		i += 2;
		get_i_and_j_for_substr(line, &i, &j);
		save_ele = ft_substr(line, j, i - j);
	}
	else if (num_of_ele == 7)
		save_ele = ft_strdup(line);
	return (save_ele);
}

int	valid_textures(char *element)
{
	if (!ft_strncmp(element, "NO ", 3))
		return (1);
	else if (!ft_strncmp(element, "SO ", 3))
		return (2);
	else if (!ft_strncmp(element, "WE ", 3))
		return (3);
	else if (!ft_strncmp(element, "EA ", 3))
		return (4);
	return (0);
}

int	is_element(char *line, int *ele)
{
	int		i;
	char	*element;
	int		ret;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (10);
	if (line[i] == '1')
		return (7);
	element = ft_substr(line, i, i + 3);
	ret = valid_textures(element);
	if (ret)
		return (free(element), (*ele)++, ret);
	free(element);
	element = ft_substr(line, i, i + 2);
	if (!ft_strncmp(element, "F ", 2))
		return (free(element), (*ele)++, 5);
	else if (!ft_strncmp(element, "C ", 3))
		return (free(element), (*ele)++, 6);
	return (free(element), 0);
}

char	**allocate_save_map(char **cnt_file)
{
	int		num_of_line_map;
	char	**save_map;

	num_of_line_map = cal_number_of_lines_map(cnt_file);
	save_map = malloc(sizeof(char *) * (num_of_line_map + 1));
	save_map[num_of_line_map] = NULL;
	return (save_map);
}
