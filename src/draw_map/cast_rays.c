/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:19:10 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/31 09:51:13 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	check_greater_or_less_in_part_horiz(t_mlx *mlx_cub, t_cast_ray *ca_ray)
{
	if (ca_ray->ra > PI)
	{
		ca_ray->ry = ((mlx_cub->y_p / 50) * 50) - 0.0001;
		ca_ray->rx = (mlx_cub->y_p - ca_ray->ry) * \
				ca_ray->atan + (float)mlx_cub->x_p;
		ca_ray->yo = -50;
		ca_ray->xo = -ca_ray->yo * ca_ray->atan;
	}
	if (ca_ray->ra < PI)
	{
		ca_ray->ry = ((mlx_cub->y_p / 50) * 50) + 50;
		ca_ray->rx = (mlx_cub->y_p - ca_ray->ry) * \
			ca_ray->atan + (float)mlx_cub->x_p;
		ca_ray->yo = 50;
		ca_ray->xo = -ca_ray->yo * ca_ray->atan;
	}
	if (ca_ray->ra == 0 || ca_ray->ra == (float)PI)
	{
		ca_ray->rx = (float)mlx_cub->x_p;
		ca_ray->ry = (float)mlx_cub->y_p;
		ca_ray->dof = mlx_cub->w / 50;
	}
}

void	check_horiental(t_mlx *mlx_cub, t_cast_ray *ca_ray)
{
	ca_ray->dof = 0;
	ca_ray->atan = -1 / tan(ca_ray->ra);
	check_greater_or_less_in_part_horiz(mlx_cub, ca_ray);
	while (ca_ray->dof < mlx_cub->w / 50)
	{
		ca_ray->mx = (int)(ca_ray->rx / 50);
		ca_ray->my = (int)(ca_ray->ry / 50);
		if (ca_ray->mx >= 0 && ca_ray->mx < mlx_cub->w / 50 \
			&& ca_ray->my >= 0 && ca_ray->my < mlx_cub->h
			/ 50 && mlx_cub->ele->map[ca_ray->my][ca_ray->mx] == '1')
		{
			ca_ray->dof = mlx_cub->w / 50;
			ca_ray->hx = ca_ray->rx;
			ca_ray->hy = ca_ray->ry;
			ca_ray->dish = calc_dist(mlx_cub->x_p, mlx_cub->y_p, \
				ca_ray->rx, ca_ray->ry);
		}
		else
		{
			ca_ray->rx += ca_ray->xo;
			ca_ray->ry += ca_ray->yo;
			ca_ray->dof += 1;
		}
	}
}

void	check_greater_or_less_in_part_verti(t_mlx *mlx_cub, t_cast_ray *ca_ray)
{
	if (ca_ray->ra > (M_PI / 2) && ca_ray->ra < ((3 * M_PI) / 2))
	{
		ca_ray->rx = ((mlx_cub->x_p / 50) * 50) - 0.0001;
		ca_ray->ry = (mlx_cub->x_p - ca_ray->rx) * \
			ca_ray->ntan + (float)mlx_cub->y_p;
		ca_ray->xo = -50;
		ca_ray->yo = -ca_ray->xo * ca_ray->ntan;
	}
	if (ca_ray->ra < (M_PI / 2) || ca_ray->ra > ((3 * M_PI) / 2))
	{
		ca_ray->rx = ((mlx_cub->x_p / 50) * 50) + 50;
		ca_ray->ry = (mlx_cub->x_p - ca_ray->rx) * \
			ca_ray->ntan + (float)mlx_cub->y_p;
		ca_ray->xo = 50;
		ca_ray->yo = -ca_ray->xo * ca_ray->ntan;
	}
	if (ca_ray->ra == 0 || ca_ray->ra == (float)PI)
	{
		ca_ray->rx = (float)mlx_cub->x_p;
		ca_ray->ry = (float)mlx_cub->y_p;
		ca_ray->dof = mlx_cub->w / 50;
	}
}

void	check_vertical(t_mlx *mlx_cub, t_cast_ray *ca_ray)
{
	ca_ray->dof = 0;
	ca_ray->ntan = -tan(ca_ray->ra);
	check_greater_or_less_in_part_verti(mlx_cub, ca_ray);
	while (ca_ray->dof < mlx_cub->w / 50)
	{
		ca_ray->mx = (int)(ca_ray->rx / 50);
		ca_ray->my = (int)(ca_ray->ry / 50);
		if (ca_ray->mx >= 0 && ca_ray->mx < mlx_cub->w / 50 && \
			ca_ray->my >= 0 && ca_ray->my < mlx_cub->h
			/ 50 && mlx_cub->ele->map[ca_ray->my][ca_ray->mx] == '1')
		{
			ca_ray->dof = mlx_cub->w / 50;
			ca_ray->vx = ca_ray->rx;
			ca_ray->vy = ca_ray->ry;
			ca_ray->disv = calc_dist(mlx_cub->x_p, mlx_cub->y_p, \
				ca_ray->rx, ca_ray->ry);
		}
		else
		{
			ca_ray->rx += ca_ray->xo;
			ca_ray->ry += ca_ray->yo;
			ca_ray->dof += 1;
		}
	}
}

unsigned int rgbToHex(char *color_rgb)
{
	char **split_color;
	int	rgb[3];
	
	split_color = ft_split(color_rgb, ',');
	rgb[0] = ft_atoi(split_color[0]);
	rgb[1] = ft_atoi(split_color[1]);
	rgb[2] = ft_atoi(split_color[2]);
	free_db(split_color);
    return ((rgb[0] & 0xFF) << 16) | ((rgb[1] & 0xFF) << 8) | (rgb[2] & 0xFF);
}

unsigned int get_texture_pixel_color(t_data_tex text,int x, int y)
{
    unsigned int hex_color;

    int pos = (y * text.line_length + x * (text.bits_per_pixel / 8));

    unsigned char r = text.addr[pos + 2];  // Red
    unsigned char g = text.addr[pos + 1];  // Green
    unsigned char b = text.addr[pos];      // Blue

    hex_color = (r << 16) | (g << 8) | b;
    return hex_color;
}

void	cast_rays(t_mlx *mlx_cub)
{
	mlx_cub->cast_ray = init_strcut_cast_ray(mlx_cub);
	while (mlx_cub->cast_ray->rays < mlx_cub->cast_ray->num_of_rays)
	{
		mlx_cub->cast_ray->dish = 100000000;
		mlx_cub->cast_ray->disv = 100000000;
		check_horiental(mlx_cub, mlx_cub->cast_ray);
		check_vertical(mlx_cub, mlx_cub->cast_ray);
		set_the_min_pos(mlx_cub);
		draw_line(mlx_cub, mlx_cub->x_p, mlx_cub->y_p);
		


		float fish_eye = mlx_cub->rot_pl - mlx_cub->cast_ray->ra;
		unsigned int	color_floor;
		color_floor = rgbToHex(mlx_cub->ele->f);
		unsigned int	color_ciel;
		color_ciel = rgbToHex(mlx_cub->ele->c);
		unsigned int color;
		if(fish_eye > 2 * PI)
			fish_eye -= 2 * PI;
		else if(fish_eye < 0)
			fish_eye += 2 * PI;
		mlx_cub->cast_ray->final_dis = mlx_cub->cast_ray->final_dis * cos(fish_eye);
		float lineH = (HIGHT*72)/mlx_cub->cast_ray->final_dis;
		if(lineH > HIGHT)
			lineH = HIGHT;
		float	celling = HIGHT/2 - lineH/2;
		float	floor = lineH + celling;
		float y = 0;
		while(y < lineH)
		{
			float texture_y = y / lineH;
			// printf("%f -- %f \n", texture_y, y);
			int texture_x = mlx_cub->cast_ray->rays ;
			if (mlx_cub->cast_ray->direction == 1)
			{
			// printf("x : %d\n",mlx_cub->cast_ray->rays);
					color = get_texture_pixel_color(mlx_cub->textures[0], texture_x, texture_y);
					my_mlx_pixel_put(&mlx_cub->data, mlx_cub->cast_ray->rays, celling + y, color);
					y++;
			}
			else if (mlx_cub->cast_ray->direction == 2)
			{
					color = get_texture_pixel_color(mlx_cub->textures[1], texture_x, texture_y);
					my_mlx_pixel_put(&mlx_cub->data, mlx_cub->cast_ray->rays, celling + y, color);
					y++;
			}
			else if (mlx_cub->cast_ray->direction == 3)
			{
					color = get_texture_pixel_color(mlx_cub->textures[2], texture_x, texture_y);
					my_mlx_pixel_put(&mlx_cub->data, mlx_cub->cast_ray->rays, celling + y, color);
					y++;
			}
			else if (mlx_cub->cast_ray->direction == 4)
			{
					color = get_texture_pixel_color(mlx_cub->textures[3], texture_x, texture_y);
					my_mlx_pixel_put(&mlx_cub->data, mlx_cub->cast_ray->rays, celling + y, color);
					y++;
			}
		}
		while(celling > 0)
		{
			my_mlx_pixel_put(&mlx_cub->data, mlx_cub->cast_ray->rays, celling, color_ciel);
			celling--;
		}
		while(floor < HIGHT)
		{
			my_mlx_pixel_put(&mlx_cub->data, mlx_cub->cast_ray->rays, floor, color_floor);
			floor++;
		}



		mlx_cub->cast_ray->ra += mlx_cub->cast_ray->dr;
		if (mlx_cub->cast_ray->ra > 2 * PI)
			mlx_cub->cast_ray->ra -= 2 * PI;
		if (mlx_cub->cast_ray->ra < 0)
			mlx_cub->cast_ray->ra += 2 * PI;
		mlx_cub->cast_ray->rays++;
	}
}
