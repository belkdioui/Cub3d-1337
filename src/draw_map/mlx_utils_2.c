/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:34:31 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/08/03 09:37:25 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	free_ele(t_ele *ele)
{
	free(ele->c);
	free(ele->f);
	free(ele->ea);
	free(ele->we);
	free(ele->no);
	free(ele->so);
	free_db(ele->map);
	free(ele);
}

void	free_all(t_global *global)
{
	free_ele(global->ele);
	free(global->map->cast_ray);
	free(global->map);
	free(global->mlx_cub);
	free(global);
}

unsigned int	rgbtohex(char *color_rgb)
{
	char	**split_color;
	int		rgb[3];

	split_color = ft_split(color_rgb, ',');
	rgb[0] = ft_atoi(split_color[0]);
	rgb[1] = ft_atoi(split_color[1]);
	rgb[2] = ft_atoi(split_color[2]);
	free_db(split_color);
	return (((rgb[0] & 0xFF) << 16) | ((rgb[1] & 0xFF) << 8) | (rgb[2] & 0xFF));
}
