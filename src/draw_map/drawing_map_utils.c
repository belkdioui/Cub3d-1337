/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:58:14 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/27 12:50:09 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	draw_line(t_game *game, int beginX, int beginY, int check)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = game->endpoint_x - beginX;
	deltay = game->endpoint_y - beginY;
	
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = beginX;
	pixely = beginY;
	while (pixels)
	{
		if (check == 1)
		{
			if (pixelx >= 0 && pixelx < width && pixely >= 0 && pixely < height)
				my_mlx_pixel_put(&game->data, pixelx, pixely, 0xebf1f2);
		}
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return (0);
}
