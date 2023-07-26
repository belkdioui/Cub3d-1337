/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:53:30 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/10/19 16:00:19 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	i;

	x = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while ((dstsize -1 != 0) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
	dst[i] = '\0';
	}
	return (x);
}
