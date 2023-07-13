/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:23:10 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/13 17:07:49 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>

# define ESC 53
# define ON_DESTROY 17

/*----- data the my_mlx_pixel_put --------*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*--------- strcut the mlx -----------*/

typedef struct s_mlx
{
	int		w;
	int		h;
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
}				t_mlx;

void	init(t_mlx *mlx_cub, t_data *data);

#endif
