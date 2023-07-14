/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:38:09 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/14 23:51:46 by rrhnizar         ###   ########.fr       */
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

void    drawing_map(char **map, t_mlx *mlx_cub, t_data *data)
{
    int i;
    int j;
    int x = 0;
    int y = -80;

    i = 0;
    while (map[i])
    {
        j = 0;
        x = 0;
        if (map[i][j] == '1')
        {
            y += 80;
            while (map[i][j] != '\n' && map[i][j] != '\0')
            {
                if (map[i][j] == '1')
                {
                    drawing_square(mlx_cub, data, x, y, 0x00ffff);
                }
                else if (map[i][j] == '0')
                    drawing_square(mlx_cub, data, x, y, 0xc90076);
                    x += 80;
                j++;
            }
        }
        if (map[i] != '\0')
            i++;
    }
}

// void    drawing_map(char **map, t_mlx *mlx_cub, t_data *data)
// {
//     int     i;
//     int     j;
//     int     x = 0;
//     int     y = 0;
//     int     iter_x = 0;
//     int     iter_y = 0;
//     i = 0;
//     while (map[i])
//     {
//         j = 0;
//         if (map[i][j] && map[i][j] == '1')
//         {
//             while (map[i])
//             {
//                 j = 0;
//                 iter_y += 80;
//                 iter_x = 0;
//                 x = 0;
//                 while(map[i][j])
//                 {
//                     iter_x += 80;
//                     while (x++ < iter_x && iter_x <= mlx_cub->w)
//                     {
//                         y = iter_y - 80;
//                         while (y++ < iter_y && iter_y <= mlx_cub->h)
//                             my_mlx_pixel_put(data, x, y, 0x00ffff * iter_y);
//                     }
//                     j++;
//                 }
//                 i++;
//             }
//         }
//         if (map[i] != '\0')
//             i++;
//     }
// }

int	main(int ac, char **av)
{
    t_mlx	mlx_cub;
	t_data	data;
	char	**map;
    
    map = get_map(ac, av);
    if (map)
	{
        init(&mlx_cub, &data, map);
        // drawing_square(&mlx_cub, &data, 0, 0);
        drawing_map(map, &mlx_cub, &data);
        // my_mlx_pixel_put(&data, 0, 0, 0xf44336);
        mlx_put_image_to_window(mlx_cub.mlx_ptr, mlx_cub.mlx_win, data.img, 0, 0);
        mlx_key_hook(mlx_cub.mlx_win, key_hock, &mlx_cub);
		mlx_hook(mlx_cub.mlx_win, ON_DESTROY, 0, close_window, &mlx_cub);
		mlx_loop(mlx_cub.mlx_ptr);
    }
    return (0);
}
