/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/08/03 12:25:04 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

void	draw(t_global *glob)
{
	draw_map(glob, glob->map, glob->ele->map);
	mlx_put_image_to_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win,
		glob->data.img, 0, 0);
	mlx_put_image_to_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win,
		glob->map->data.img, 0, 0);
}

void	finish(t_global *glob)
{
	draw(glob);
	mlx_hook(glob->mlx_cub->mlx_win, 2, 0, key_hock, glob);
	mlx_hook(glob->mlx_cub->mlx_win, ON_DESTROY, 0, close_window, glob);
	mlx_loop(glob->mlx_cub->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_global	*glob;

	glob = malloc(sizeof(t_global));
	if (!glob)
		exit(1);
	glob = init_global(glob, ac, av);
	if (!glob)
		return (0);
	finish(glob);
	return (1);
}
