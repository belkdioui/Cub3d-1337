/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:05:03 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/08/03 14:44:32 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			len++;
			while (*s != c && *s != '\0')
			{
				s++;
			}
		}
	}
	return (len);
}

static char	**result(char **str, char const *s, char c, int len)
{
	int	j;
	int	k;

	k = 0;
	while (len)
	{
		j = 0;
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			len--;
			while (*s != '\0' && *s != c)
			{
				s++;
				j++;
			}
		}
		str[k] = ft_calloc(j + 1, sizeof(char *));
		ft_memcpy(str[k], s - j, j);
		k++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		len;

	if (!s)
		return (0);
	len = count_words(s, c);
	str = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!str)
		return (0);
	return (result(str, s, c, len));
}
