/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:26:07 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/11/21 08:44:52 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		free(save);
		return (0);
	}
	str = ft_substr(save, i + 1, len - i);
	free(save);
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
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_and_add(save[fd], fd);
	if (!save[fd])
		return (NULL);
	line = befor(save[fd]);
	save[fd] = after(save[fd]);
	return (line);
}
