/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:38:09 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/13 17:09:23 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>
#include <errno.h>

int	main(void)
{
	perror("");
	printf("\n");
	printf("yy: %s\n", strerror(errno));
	return (0);
}
