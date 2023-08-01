/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:55 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/08/01 01:42:45 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

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
	// if (text.addr)
	// {
    	unsigned char r = text.addr[pos + 2];  // Red
    	unsigned char g = text.addr[pos + 1];  // Green
    	unsigned char b = text.addr[pos];      // Blue
   		hex_color = (r << 16) | (g << 8) | b;
	// }
    return hex_color;
}


void	draw_view(t_global *glob)
{
	float fish_eye = glob->ra - glob->rot_pl;
	glob->final_dis = (glob->final_dis * cos(fish_eye) / glob->map->h_sq);
	float lineH = height / (glob->final_dis);
	
	unsigned int	color_floor;
	color_floor = rgbToHex(glob->ele->f);
	unsigned int	color_ciel;
	color_ciel = rgbToHex(glob->ele->c);
	unsigned int color;

	// // float y = 0;
	
	float	celling = height / 2 - lineH / 2;
	if(celling < 0)
		celling = 0;
	// float pixel = glob->final_dis / glob->textures[0].hei;
	float pixel = glob->textures[0].hei / lineH;
	float err = lineH / 2 - height/2;
	if(err < 0)
		err=0;
	float	floor = lineH + celling;
	float y = err * pixel;
	int	i = 0;
	// int y = 0;
	// printf("Y= %f\n", pixel);
	// exit(1);
	// printf("H= %f\n", lineH);
	float		texture_x;// = (glob->map->cast_ray->ray_pos_x - ((int)(glob->map->cast_ray->ray_pos_x / 10) * 10)) * ((float)glob->textures[2].wid / 10);
	// if()
		
	// if()
		// texture_x = (glob->map->cast_ray->ry - ((int)(glob->map->cast_ray->ry / 10) * 10)) * ((float)glob->textures[2].wid / 10);
	// printf("%f\n", glob->map->cast_ray->ray_pos_x);
	// exit(1);
	texture_x = glob->map->cast_ray->ray_pos_x * ((float)glob->textures[2].wid / 10);
	while(i < lineH && i < height)
	{
		// float		texture_y;
		if (glob->map->cast_ray->direction == 1)
		{
			// texture_y = y / lineH * (glob->textures[0].hei - 1);
			color = get_texture_pixel_color(glob->textures[0], texture_x, y);
			// printf("%d\n",color);
			my_mlx_pixel_put(&glob->data, glob->rays ,celling + i, color);
		}
		else if (glob->map->cast_ray->direction == 2)
		{
			// texture_y = y / lineH * (glob->textures[1].hei - 1);
			color = get_texture_pixel_color(glob->textures[1], texture_x, y);
			// printf("%d\n",color);
			my_mlx_pixel_put(&glob->data, glob->rays, celling + i, color);
		}
		else if (glob->map->cast_ray->direction == 3)
		{
			// texture_y = y / lineH * (glob->textures[2].hei - 1);
			color = get_texture_pixel_color(glob->textures[2], texture_x, y);
			// printf("%d\n",color);
			my_mlx_pixel_put(&glob->data, glob->rays, celling + i, color);
		}
		else if (glob->map->cast_ray->direction == 4)
		{
			// texture_y = y / lineH * (glob->textures[3].hei - 1);
			color = get_texture_pixel_color(glob->textures[3], texture_x, y);
			// printf("%d\n",color);
			my_mlx_pixel_put(&glob->data, glob->rays, celling + i, color);
		}
		y+=pixel;
		i++;
	}
	while(celling > 0)
	{
		my_mlx_pixel_put(&glob->data, glob->map->cast_ray->rays, celling, color_ciel);
		celling--;
	}
	while(floor < glob->h)
	{
		my_mlx_pixel_put(&glob->data, glob->map->cast_ray->rays, floor, color_floor);
		floor++;
	}
}
