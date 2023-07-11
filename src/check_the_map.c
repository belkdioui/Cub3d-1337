/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:00:19 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/11 20:15:35 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3D.h"

char *ret_element(char *line, int num_of_ele)
{
	int     i;
	char *save_ele;
	
	i = 0;
	save_ele = NULL;
	while (line[i] == ' ')
		i++;
	if (num_of_ele >= 1 && num_of_ele <= 4)
	{
		i += 3;
		while (line[i] == ' ')
			i++;
		save_ele = ft_substr(line, i, ft_strlen(line));
	}
	else if (num_of_ele == 5 || num_of_ele == 6)
	{
		i += 2;
		while (line[i] == ' ')
			i++;
		save_ele = ft_substr(line, i, ft_strlen(line));
	}
	else if (num_of_ele == 7)
		save_ele = ft_strdup(line);
	return (save_ele);
}

int is_element(char *line, int *ele)
{
	int     i;
	char    *element;
	
	i = 0;
	while (line[i] == ' ')
		i++;
	element = ft_substr(line, i, i + 3);
	if (!ft_strncmp(element, "NO ", 3))
		return (free (element), (*ele)++, 1);
	else if (!ft_strncmp(element, "SO ", 3))
		return (free(element), (*ele)++, 2);
	else if (!ft_strncmp(element, "WE ", 3))
		return (free(element), (*ele)++, 3);
	else if (!ft_strncmp(element, "EA ", 3))
		return (free(element), (*ele)++, 4);
	free (element);
	element = ft_substr(line, i, i + 2);
	if (!ft_strncmp(element, "F ", 2))
		return (free(element), (*ele)++, 5);
	else if (!ft_strncmp(element, "C ", 3))
		return (free(element), (*ele)++, 6);
	free (element);
	element = ft_substr(line, i, i + 1);
	if (!ft_strncmp(element, "1", 1))
		return (free(element), 7);
	if (!ft_strncmp(element, "\n", 1))
		return (free(element), 10);
	return (free(element), 0);
}

int cal_number_of_lines_map(char **cnt_file)
{
	int i;
	int j;
	int is_ele;
	int num_of_ele;

	j = 0;
	num_of_ele = 0;
	i = 0;
	while(cnt_file[i])
	{
		num_of_ele = is_element(cnt_file[i], &is_ele);
		if(num_of_ele == 7)
			j++;
		i++;
	}
	return (j);
}
void free_db(char **arr)
{
	int i;
	
	i=0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
int is_element_and_saveit(char **cnt_file, int which_ele)
{
	int i;
	int num_of_ele;
	char *save;
	int is_ele;
	char **save_map;
	int num_of_line_map;
	save = NULL;
	int j;

	j = 0;
	i = 0;
	is_ele = 0;
	if (which_ele == 7)
	{
		num_of_line_map = cal_number_of_lines_map(cnt_file);
		save_map = malloc(sizeof(char *) * (num_of_line_map + 1));
		save_map[num_of_line_map] = NULL;
	}
	while(cnt_file[i])
	{
		num_of_ele = is_element(cnt_file[i], &is_ele);
		if (!num_of_ele)
			return (0);
		if (num_of_ele == 7 && is_ele != 6)
			return (0);
		if (num_of_ele == 10 && is_ele == 6)
			return (0);
		if (which_ele && num_of_ele == which_ele)
		{
			if(num_of_ele == 7)
			{
				save_map[j] = ret_element(cnt_file[i], num_of_ele);
				j++;
			}
			else
				save = ret_element(cnt_file[i], num_of_ele);
		}
		if(j == 0 && save)
			return (1);
		i++;
	}
	return (1);
}

int check_the_map(char **cnt_file)
{
	if(!is_element_and_saveit(cnt_file, 1))
		return (0);
	return(1);
}
