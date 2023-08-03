/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:58:54 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/08/03 14:45:26 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (n > 0)
	{
		while (s1[i] != '\0' && s1[i] == s2[i])
		{
			if (i < (n - 1))
				i++;
			else
				return (0);
		}
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
