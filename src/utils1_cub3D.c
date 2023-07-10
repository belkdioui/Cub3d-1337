/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_cub3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:38:08 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/10 18:48:42 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	search_and_ret_place(char *av)
{
	int	i;

	i = 0;
	while (av)
	{
		if (av[i] == '.')
			break ;
		i++ ;
	}
	return (i);
}
