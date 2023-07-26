/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:11:56 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/25 18:10:14 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "inc/cub3D.h"

#define  height 1080
#define	width 1920
#define  height_map 150
#define	width_map 250
# define ESC 53

typedef struct s_dataa
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_dataa;

typedef struct s_mlxx
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		w_sq;
	int		h_sq;
	int		w_sq_map;
	int		h_sq_map;
	t_dataa	data;
	t_dataa	data2;
	char	**map;
}			t_mlxx;

int	key_hock2(int keycode, t_mlxx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->data.img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		exit(0);
	}
	return (0);
}

void	my_mlx_pixel_putt(t_dataa *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_map(t_mlxx *mlx_cub)
{
	mlx_cub->map = malloc(sizeof(char *) * 4);
	int i = 0;
	mlx_cub->map[3] = NULL;
	while (mlx_cub->map[i])
	{
		mlx_cub->map[i] = ft_strdup("1111");
		i++;
	}
	
}
void	calcul_width_height_the_square(t_mlxx *mlx_cub)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	fill_map(mlx_cub);
	while (mlx_cub->map[h])
	{
		while (mlx_cub->map[h][w])
			w++;
		h++;
	}
	mlx_cub->h_sq = height / h;
	mlx_cub->w_sq = width / w;
	mlx_cub->h_sq_map = height_map / h;
	mlx_cub->w_sq_map = width_map / w;
}

static void	drawing_square(t_mlxx *mlx_cub, int x, int y, t_dataa data)
{
	int	tmp_x;
	int	tmp_y;
	tmp_y = y;
	while (tmp_y < (y + mlx_cub->h_sq - 1) && (y + mlx_cub->h_sq) <= height)
	{
		tmp_x = x;
		while (tmp_x < (x + mlx_cub->w_sq - 1) && (x + mlx_cub->w_sq) <= width)
		{
			my_mlx_pixel_putt(&data, tmp_x, tmp_y, 0x00cc1a);
			tmp_x++;
		}
		tmp_y++;
	}
}



static void	drawing_square_map(t_mlxx *mlx_cub, int x, int y, t_dataa data)
{
	int	tmp_x;
	int	tmp_y;
	tmp_y = y;
	while (tmp_y < (y + mlx_cub->h_sq_map - 1) && (y + mlx_cub->h_sq_map) <= height_map)
	{
		tmp_x = x;
		while (tmp_x < (x + mlx_cub->w_sq_map - 1) && (x + mlx_cub->w_sq_map) <= width_map)
		{
			my_mlx_pixel_putt(&data, tmp_x, tmp_y, 0x00cc1a);
			tmp_x++;
		}
		tmp_y++;
	}
}


int main()
{
	int i = 0;
	int	j = 0;
	t_mlxx	*mlx;
	mlx = malloc(sizeof(t_mlxx));

	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, width, height, "cub3d");
	/* initialization the first image */
	mlx->data.img = mlx_new_image(mlx->mlx_ptr, width, height);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel,\
		 &mlx->data.line_length, &mlx->data.endian);
	/* initialization the second image */
	mlx->data2.img = mlx_new_image(mlx->mlx_ptr, 250, 150);
	mlx->data2.addr = mlx_get_data_addr(mlx->data2.img, &mlx->data2.bits_per_pixel,\
		 &mlx->data2.line_length, &mlx->data2.endian);
	calcul_width_height_the_square(mlx);
	while (i <= height)
	{
		j = 0;
		while (j <= width)
		{
			drawing_square(mlx, j, i, mlx->data);
			j += mlx->w_sq;
		}
		i += mlx->h_sq;
	}
	// my_mlx_pixel_putt(&mlx->data2, 0, 0, 0x00cc1a);
	i = 0;
	while (i <= height_map)
	{
		j = 0;
		while (j <= width_map)
		{
			drawing_square_map(mlx, j, i, mlx->data2);
			j += mlx->w_sq_map;
		}
		i += mlx->h_sq_map;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->data.img, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->data2.img, 0, 0);
	mlx_hook(mlx->mlx_win, 2, 0, key_hock2, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}