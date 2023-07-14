/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_element_and_return_it-1.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:56:11 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/14 10:48:32 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/cub3D.h"
#include "../cub3d.h"

char	*ret_element(char *line, int num_of_ele)
{
	int		i;
	char	*save_ele;

	i = 0;
	save_ele = NULL;
	while (line[i] == ' ')
		i++;
	if (num_of_ele >= 1 && num_of_ele <= 4)
	{
		i += 3;
		while (line[i] == ' ')
			i++;
		save_ele = ft_substr(line, i, ft_strlen(line));
	}
	else if (num_of_ele == 5 || num_of_ele == 6)
	{
		i += 2;
		while (line[i] == ' ')
			i++;
		save_ele = ft_substr(line, i, ft_strlen(line));
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
	element = ft_substr(line, i, i + 3);
	ret = valid_textures(element);
	if (ret)
		return (free (element), (*ele)++, ret);
	free (element);
	element = ft_substr(line, i, i + 2);
	if (!ft_strncmp(element, "F ", 2))
		return (free(element), (*ele)++, 5);
	else if (!ft_strncmp(element, "C ", 3))
		return (free(element), (*ele)++, 6);
	free (element);
	element = ft_substr(line, i, i + 1);
	if (!ft_strncmp(element, "1", 1))
		return (free(element), 7);
	if (!ft_strncmp(element, "\n", 1))
		return (free(element), 10);
	return (free(element), 0);
}
