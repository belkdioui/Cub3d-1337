/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/12 10:32:20 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	char	**cnt_file;
	t_ele	*ele;

	cnt_file = ver_and_ret_map(ac, av);
	if (!cnt_file)
		return (ft_putstr_fd("error in the name\n", 2), 0);
	ele = malloc(sizeof(t_ele));
	if (!check_the_map(cnt_file, ele))
		return (ft_putstr_fd("error in the map\n", 2), 0);
	printf("\n\n\n");
	system("leaks cub3D");
}
