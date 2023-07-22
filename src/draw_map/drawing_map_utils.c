/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/22 17:16:58 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	window_coloring(t_mlx *mlx_cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx_cub->w)
	{
		y = 0;
		while (y < mlx_cub->h)
		{
			my_mlx_pixel_put(&mlx_cub->data, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

float calc_dist(float px, float py, float dx, float dy)
{
	float a;
	float b;
	float c;

	a = (dx -px);
	b = (dy -py);
	c = sqrt((a*a) + (b*b));
	return c;
}
static void	drawing_square(t_mlx *mlx_cub, int x, int y)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	while (tmp_x++ < x + 49 && x + 50 <= mlx_cub->w)
	{
		tmp_y = y;
		while (tmp_y++ < y + 49 && y + 50 <= mlx_cub->h)
			my_mlx_pixel_put(&mlx_cub->data, tmp_x, tmp_y, 0x000000);
	}
}

static void	drawing_player(t_mlx *mlx_cub, int x, int y)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	while (tmp_x++ < x + 10 && x + 10 <= mlx_cub->w)
	{
		tmp_y = y;
		while (tmp_y++ < y + 10 && y + 10 <= mlx_cub->h)
			my_mlx_pixel_put(&mlx_cub->data, tmp_x, tmp_y, 0xFF0000);
	}
}

int draw_line(t_mlx *mlx_cub, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    if (pixels == 0) {
        my_mlx_pixel_put(&mlx_cub->data, beginX, beginY, color);
        return 0;
    }

    deltaX /= pixels;
    deltaY /= pixels;

    double pixelX = beginX;
    double pixelY = beginY;

    while (pixels) {
        if(pixelX >= 0 && pixelX < mlx_cub->w && pixelY >= 0 && pixelY < mlx_cub->h)
	        my_mlx_pixel_put(&mlx_cub->data, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return 0;
}


void	drawing_map(char **map, t_mlx *mlx_cub)
{
	int	i;
	int	j;

	mlx_cub->x = 0;
	mlx_cub->y = -50;
	i = -1;
	window_coloring(mlx_cub);
	while (map[++i])
	{
		j = -1;
		mlx_cub->x = 0;
		mlx_cub->y += 50;
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				drawing_square(mlx_cub, mlx_cub->x, mlx_cub->y);
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				mlx_cub->x_p = mlx_cub->x + mlx_cub->x_p_move;
				mlx_cub->y_p = mlx_cub->y + mlx_cub->y_p_move;
				drawing_player(mlx_cub, mlx_cub->x_p, mlx_cub->y_p);
			}
			mlx_cub->x += 50;
		}
	}
		// float pdx = (mlx_cub->x_p + 5) + cos(mlx_cub->rot_pl) * 50;
		// float pdy = (mlx_cub->y_p + 5) + sin(mlx_cub->rot_pl) * 50;
		// float angle_degrees = 60.0f;
		// float angle_radians = angle_degrees * (M_PI / 180.0f);
		// while(angle_radians >= -angle_radians)
		// {
		// 	float pdx_top = pdx + cos(mlx_cub->rot_pl + angle_radians) * 50;
		// 	float pdy_top = pdy + sin(mlx_cub->rot_pl + angle_radians) * 50;
		// 	float pdx_bottom = pdx + cos(mlx_cub->rot_pl - angle_radians) * 50;
		// 	float pdy_bottom = pdy + sin(mlx_cub->rot_pl - angle_radians) * 50;
			// draw_line(mlx_cub, mlx_cub->x_p + 5, mlx_cub->y_p + 5, pdx, pdy, 0x00FF00);
		// 	draw_line(mlx_cub, mlx_cub->x_p + 5, mlx_cub->y_p + 5, pdx_top, pdy_top, 0x000000);
		// 	draw_line(mlx_cub, mlx_cub->x_p + 5, mlx_cub->y_p + 5, pdx_bottom, pdy_bottom, 0x000000);
		// 	angle_radians -= 0.0008;
		// }
	int dof, mx, my;
	float xo,yo, ra;
	int NUM_OF_RAYS = 1920;

	float DR = ((2 * PI) / NUM_OF_RAYS) / ((float)360 / 90);
	ra = mlx_cub->rot_pl - (DR * NUM_OF_RAYS / 2);
	if(ra > 2 * PI)
		ra -= 2 * PI;
	if(ra < 0)
		ra += 2 * PI;
	int rays = 0;
	float ry;
	float rx;
	float disH;
	float hx;
	float hy;
	float disV;
	float vx;
	float vy;
	float final_dis;
	while(rays < NUM_OF_RAYS)
	{
		disH = 100000000;
		disV = 100000000;
		/*Check Horizental*/
		dof = 0;
		float aTan = -1/tan(ra);
		if(ra > PI)
		{
			// printf("ra > PI -- ry: %f rx: %f  ra: %f\n",ry,rx,ra);
			ry = ((mlx_cub->y_p / 50) * 50) - 0.0001;
			rx = (mlx_cub->y_p - ry) * aTan  + (float)mlx_cub->x_p;
			yo  = -50;
			xo  = -yo*aTan;
		}
		if(ra < PI)
		{
			// printf("ra < PI ++ ry: %f rx: %f  ra: %f\n",ry,rx,ra);
			ry = ((mlx_cub->y_p / 50) * 50) + 50;
			rx = (mlx_cub->y_p - ry) * aTan + (float)mlx_cub->x_p;
			yo  =  50;
			xo  = -yo*aTan;
		}
		if (ra == 0 || ra == (float)PI)
		{
			// printf("ra == PI ++ ry: %f rx: %f  ra: %f\n",ry,rx,ra);
			rx = (float)mlx_cub->x_p;
			ry = (float)mlx_cub->y_p;
			dof = mlx_cub->w/50;
		}
		
		while(dof < mlx_cub->w/50)
		{
			mx = (int) (rx / 50);
			my = (int) (ry / 50);
			if(mx >= 0 && mx < mlx_cub->w/50 && my >= 0 && my < mlx_cub->h/50 && mlx_cub->ele->map[my][mx] == '1')
			{
				//hit  a wall;
				dof = mlx_cub->w/50;
				hx = rx;
				hy  =ry;
				disH = calc_dist(mlx_cub->x_p, mlx_cub->y_p, rx, ry);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		// draw_line(mlx_cub, mlx_cub->x_p, mlx_cub->y_p, rx, ry,0x00FF00);

		/*Check Vertical*/
		dof = 0;
		float nTan = -tan(ra);
		if(ra > P2 && ra <P3)
		{
			// printf("+++");
			// printf("ra > PI -- ry: %f rx: %f  ra: %f\n",ry,rx,ra);
			rx = ((mlx_cub->x_p / 50) * 50) - 0.0001;
			ry = (mlx_cub->x_p - rx) * nTan  + (float)mlx_cub->y_p;
			xo  = -50;
			yo  = -xo*nTan;
		}
		if(ra < P2 || ra > P3)
		{
			// printf("---");
			rx = ((mlx_cub->x_p / 50) * 50) + 50;
			ry = (mlx_cub->x_p - rx) * nTan  + (float)mlx_cub->y_p;
			xo  = 50;
			yo  = -xo*nTan;
		}
		if (ra == 0 || ra == (float)PI)
		{
			// printf("====");
			// printf("ra == PI ++ ry: %f rx: %f  ra: %f\n",ry,rx,ra);
			rx = (float)mlx_cub->x_p;
			ry = (float)mlx_cub->y_p;
			dof = mlx_cub->w/50;
		}
		
		while(dof < mlx_cub->w/50)
		{
			mx = (int) (rx / 50);
			my = (int) (ry / 50);
			if(mx >= 0 && mx < mlx_cub->w/50 && my >= 0 && my < mlx_cub->h/50 && mlx_cub->ele->map[my][mx] == '1')
			{
				//hit  a wall;
				dof = mlx_cub->w/50;
				vx = rx;
				vy  =ry;
				disV = calc_dist(mlx_cub->x_p, mlx_cub->y_p, rx, ry);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}

		// draw_line(mlx_cub, mlx_cub->x_p, mlx_cub->y_p, rx, ry,0xFF0000);


		//pick the shortest ray
		if(disH < disV )
		{
			rx = hx;
			ry = hy;
			// final_dis = disH;
		}
		else
		{
			rx = vx;
			ry = vy;
			// final_dis = disV;
		}
		(void) final_dis;
		//final ray
		draw_line(mlx_cub, mlx_cub->x_p, mlx_cub->y_p, rx, ry,0x0000FF);
				
		
		// printf("rx: %f ry: %f ra: %f\n",rx,ry,ra);
		ra += DR;
		if(ra > 2 * PI)
			ra -= 2 * PI;
		if(ra < 0)
			ra += 2 * PI;
		rays++;
	}
}
