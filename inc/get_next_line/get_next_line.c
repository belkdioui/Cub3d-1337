/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:06:01 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/14 11:46:30 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*befor(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = ft_substr(save, 0, i + 1);
	return (str);
}

char	*after(char *save)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(save);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (0);
	}
	str = ft_substr(save, i + 1, len - i);
	free (save);
	return (str);
}

char	*read_and_add(char *save, int fd)
{
	char	*buff;
	int		byt;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	byt = 1;
	if (!save)
		save = ft_calloc(1, 1);
	while (!ft_strchr(save, '\n') && byt != 0)
	{
		byt = read(fd, buff, BUFFER_SIZE);
		if (byt == -1)
		{
			free(save);
			free(buff);
			return (NULL);
		}
		buff[byt] = '\0';
		save = ft_strjoin_1(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_add(save, fd);
	if (!save)
		return (NULL);
	line = befor(save);
	save = after(save);
	return (line);
}
