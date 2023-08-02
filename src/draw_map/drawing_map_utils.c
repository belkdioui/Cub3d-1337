/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/29 17:13:45 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	draw_line(t_map *map_draw, int beginX, int beginY)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = map_draw->endpoint_x - beginX;
	deltay = map_draw->endpoint_y - beginY;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = beginX;
	pixely = beginY;
	while (pixels)
	{
		if (pixelx >= 0 && pixelx < width && pixely >= 0 && pixely < height)
			my_mlx_pixel_put(&map_draw->data, pixelx, pixely, 0xebf1f2);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return (0);
}
