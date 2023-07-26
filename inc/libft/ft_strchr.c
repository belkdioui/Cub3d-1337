/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:42:44 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/10/18 09:38:35 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(char *)s != (char)c && *(char *)s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
