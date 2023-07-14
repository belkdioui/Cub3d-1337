/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:50:19 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/10/18 11:08:55 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*negative(long long int x, int j, int i)
{
	char	*s;

	s = malloc(sizeof(char) * i);
	if (!s)
		return (NULL);
	i--;
	while (--i > 0)
	{
		s[i] = x % 10 + '0';
		x /= 10;
	}
	s[i] = '-';
	s[j + 1] = '\0';
	return (s);
}

static char	*notnegat(long long int x, int j, int i)
{
	char	*s;

	s = malloc(sizeof(char) * i + 1);
	if (!s)
		return (NULL);
	while (i-- > 0)
	{
		s[i] = x % 10 + '0';
		x /= 10;
	}
	s[j] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int				i;
	int				j;
	long long int	x;

	i = 0;
	j = 0;
	x = n;
	if (x == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	if (x < 0)
	{
		j = i;
		x = -x;
		i += 2;
		return (negative(x, j, i));
	}
	j = i;
	return (notnegat(x, j, i));
}
