/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/26 17:00:35 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

t_ele	*get_map(int ac, char **av, t_gloabl *glob)
{
	char	**cnt_file;
	t_ele	*ele;

	cnt_file = ver_and_ret_map(ac, av);
	if (!cnt_file)
	{
		ft_putstr_fd("error in the name\n", 2);
		exit(1);
	}
	ele = malloc(sizeof(t_ele));
	if (!ele)
		exit(1);
	if (!check_the_map(cnt_file, ele, glob))
	{
		ft_putstr_fd("error in the map\n", 2);
		exit(1);
	}
	free_db(cnt_file);
	return (ele);
}

void	finish(t_gloabl *glob)
{
	draw_game(glob->game, glob->ele->map);
	draw_game(glob->mini_game, glob->ele->map);
	mlx_put_image_to_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win,\
		glob->game->data.img, 0, 0);
	mlx_put_image_to_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win,\
		glob->mini_game->data.img, 0, 0);
	mlx_hook(glob->mlx_cub->mlx_win, 2, 0, key_hock, glob);
	mlx_hook(glob->mlx_cub->mlx_win, ON_DESTROY, 0, close_window, glob);
	mlx_loop(glob->mlx_cub->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_gloabl	*glob;

	glob = malloc(sizeof(t_gloabl));
	if (!glob)
		exit(1);
	glob = init_global(glob, ac, av);
	finish(glob);
	return (1);
}
