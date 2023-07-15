/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:38:09 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/15 12:50:14 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    drawing_square(t_mlx *mlx_cub, t_data *data, int x, int y, int color)
{
    int tmp_x;
    int tmp_y;

    tmp_x = x;
    while (tmp_x++ < x + 79 && x + 80 <= mlx_cub->w)
    {
        tmp_y = y;
        while (tmp_y++ < y + 79 && y + 80 <= mlx_cub->h)
            my_mlx_pixel_put(data, tmp_x, tmp_y, color);
    }
}

void    drawing_player(t_data *data, int x, int y)
{
    int tmp_x;
    int tmp_y;
    
    tmp_x = x;
    while (tmp_x++ < x + 30)
    {
        tmp_y = y;
        while (tmp_y++ < y + 30)
            my_mlx_pixel_put(data, tmp_x, tmp_y, 0xFF0000);
    }
}

int search_beginning_the_map(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] == ' ')
            j++;
        if (map[i][j] == '1')
            return (i);
        i++;
    }
    return (0);
}

void    drawing_map(char **map, t_mlx *mlx_cub, t_data *data)
{
    int i;
    int j;
    int x = 0;
    int y = -80;

    i = search_beginning_the_map(map);
    while (map[i])
    {
        j = 0;
        x = 0;
        y += 80;
        while (map[i][j] != '\n' && map[i][j] != '\0')
        {
            if (map[i][j] == '1')
                drawing_square(mlx_cub, data, x, y, 0x000000);
            else if (map[i][j] == '0') // this for drawing player
                drawing_player(data, x, y);
            x += 80;
            j++;
        }
        i++;
    }
}

void    coloring_window(t_mlx *mlx_cub, t_data *data)
{
    int x;
    int y;

    x = 0;
    while (x < mlx_cub->w)
    {
        y = 0;
        while (y < mlx_cub->h)
        {
            my_mlx_pixel_put(data, x, y, 0xFFFFFF);
            y++;
        }
        x++;
    }
}

int	main(int ac, char **av)
{
    t_mlx	mlx_cub;
	t_data	data;
	char	**map;
    
    map = get_map(ac, av);
    if (map)
	{
        init(&mlx_cub, &data, map);
        coloring_window(&mlx_cub, &data);
        drawing_map(map, &mlx_cub, &data);
        mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win, data.img, 0, 0);
        mlx_key_hook(mlx_cub.mlx_win, key_hock, &mlx_cub);
		mlx_hook(mlx_cub.mlx_win, ON_DESTROY, 0, close_window, &mlx_cub);
		mlx_loop(mlx_cub.mlx_ptr);
    }
    return (0);
}
