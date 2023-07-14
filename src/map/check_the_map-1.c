/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map-1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:48:04 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/14 10:49:38 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	check_rgb(char *rgb)
{
	char	**split_rgb;
	int		i;
	int		j;
	int		num_rgb;

	i = 0;
	split_rgb = ft_split(rgb, ',');
	while (split_rgb[i])
	{
		j = 0;
		while (split_rgb[i][j])
		{
			if (!ft_isdigit(split_rgb[i][j]) && split_rgb[i][j] != '\n')
				return (free_db(split_rgb), 0);
			j++;
		}
		num_rgb = ft_atoi(split_rgb[i]);
		if (!(num_rgb >= 0 && num_rgb <= 255))
			return (free_db(split_rgb), 0);
		i++;
	}
	if (i != 3)
		return (free_db(split_rgb), 0);
	return (free_db(split_rgb), 1);
}

int	check_img(char *textures)
{
	int	fd;

	textures = ft_strtrim(textures, "\n");
	fd = open(textures, O_RDONLY);
	if (fd == -1)
		return (free(textures), 0);
	return (free(textures), 1);
}
