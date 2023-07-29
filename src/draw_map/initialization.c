/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:33:58 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/27 00:33:42 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	protection(t_mlx *mlx_cub)
{
	free(mlx_cub->mlx_ptr);
	perror("");
	exit(1);
}

static void	width_and_height(int *width, int *height, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
			j++;
		*width = j;
		i++;
	}
	*height = i;
}

void	set_textures(t_mlx *mlx_cub)
{
	int		i;
	char	*path;

	i = 0;
	mlx_cub->textures = malloc(sizeof(t_data_tex) * 4);
	while (i < 4)
	{
		if(i == 0)
			path = ft_strdup(mlx_cub->ele->no);
		if(i == 1)
			path = ft_strdup(mlx_cub->ele->so);
		if(i == 2)
			path = ft_strdup(mlx_cub->ele->we);
		if(i == 3)
			path = ft_strdup(mlx_cub->ele->ea);
		mlx_cub->textures[i].img = mlx_xpm_file_to_image(mlx_cub->mlx_ptr, path, &mlx_cub->textures[i].width, &mlx_cub->textures[i].height);
    	mlx_cub->textures[i].addr = mlx_get_data_addr(mlx_cub->textures[i].img, &mlx_cub->textures[i].bits_per_pixel, &mlx_cub->textures[i].line_length, &mlx_cub->textures[i].endian);
		free(path);
		i++;
	}
}

void	init(t_mlx *mlx_cub, char **map)
{
	mlx_cub->mlx_ptr = mlx_init();
	width_and_height(&mlx_cub->w, &mlx_cub->h, map);
	mlx_cub->h *= 50;
	mlx_cub->w *= 50;
	mlx_cub->y_p_move = 0;
	mlx_cub->x_p_move = 0;
	mlx_cub->x_p = 0;
	mlx_cub->y_p = 0;
	mlx_cub->x = 0;
	mlx_cub->y = -50;
	if (!mlx_cub->mlx_ptr)
	{
		perror("");
		exit(1);
	}
	mlx_cub->mlx_win = mlx_new_window(mlx_cub->mlx_ptr, WIDTH/*mlx_cub->w*/, HIGHT/*mlx_cub->h*/,
			"cub3d");
	if (!mlx_cub->mlx_win)
		protection(mlx_cub);
	mlx_cub->data.img = mlx_new_image(mlx_cub->mlx_ptr, WIDTH/*mlx_cub->w*/, HIGHT/*mlx_cub->h*/);
	if (!mlx_cub->data.img)
		protection(mlx_cub);
	mlx_cub->data.addr = mlx_get_data_addr(mlx_cub->data.img,
			&mlx_cub->data.bits_per_pixel, &mlx_cub->data.line_length,
			&mlx_cub->data.endian);
	if (!mlx_cub->data.addr)
		protection(mlx_cub);
	set_textures(mlx_cub);
}
