/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifaction_and_return_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:39:10 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/14 10:49:05 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	check_the_name(int ac, char **av)
{
	int		i;
	char	*after_dot;

	after_dot = NULL;
	i = 0;
	if (ac != 2)
		return (0);
	else
	{
		if (ft_strchr(av[1], '.'))
		{
			i = search_and_ret_place(av[1]);
			after_dot = ft_substr(av[1], i + 1, ft_strlen(av[1]));
			if (!ft_strncmp(after_dot, "cub", 4))
			{
				free(after_dot);
				return (1);
			}
		}
	}
	if (after_dot)
		free(after_dot);
	return (0);
}

int	cal_num_of_lines(char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (i);
}

void	fill_the_map(int fd, char **cnt_file)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0)
		{
			cnt_file[i] = ft_strdup(line);
			free(line);
		}
		else
		{
			line = get_next_line(fd);
			if (!line)
			{
				free(line);
				break ;
			}
			cnt_file[i] = ft_strdup(line);
			free(line);
		}
		i++;
	}
}

char	**set_the_cnt_of_file_in_db(char **av)
{
	int		fd;
	char	**cnt_file;
	int		num_of_lines;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	num_of_lines = cal_num_of_lines(av);
	cnt_file = malloc(sizeof(char *) * (num_of_lines + 1));
	cnt_file[num_of_lines] = NULL;
	fill_the_map(fd, cnt_file);
	return (cnt_file);
}

char	**ver_and_ret_map(int ac, char **av)
{
	char	**cnt_file;

	if (!check_the_name(ac, av))
		return (0);
	cnt_file = set_the_cnt_of_file_in_db(av);
	return (cnt_file);
}
