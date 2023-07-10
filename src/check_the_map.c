/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:00:19 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/10 20:22:56 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3D.h"

//create function is_element

int check_the_map(char **cnt_file)
{
    int i;
    int j;
    int num_of_ele;

    j = 0;
    i = 0;
    num_of_ele = 0;
    while(cnt_file[i])
    {
        if (is_element(cnt_file[i]) == 0) //if err like sq
            return(1);
        else if (is_element(cnt_file[i]) == 1)//is element
            num_of_ele++;
        i++;
    }
    return(0);
}
