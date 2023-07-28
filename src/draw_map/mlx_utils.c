/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:16:56 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/27 17:01:16 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	close_window(t_mlx *mlx_cub)
{
	mlx_destroy_image(mlx_cub->mlx_ptr, mlx_cub->data.img);
	mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	free_ele(mlx_cub->ele);
	free(mlx_cub);
	system("leaks cub3D");
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

void		check_size(t_gloabl *glob, t_game *game)
{
	if (game->w_sq * game->j > game->w || game->h_sq * game->i > game->h)
	{
		// free here
		printf("error\n");
		exit(1);
	}
}

void	free_ele(t_ele *ele)
{
	free(ele->c);
	free(ele->f);
	free(ele->ea);
	free(ele->we);
	free(ele->no);
	free(ele->so);
	free_db(ele->map);
	free(ele);
}

void	free_all(t_gloabl *global)
{
	free_ele(global->ele);
	free(global->game->cast_ray);
	free(global->mini_game->cast_ray);
	free(global->game);
	free(global->mini_game);
	free(global->mlx_cub);
}