/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:51:41 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/07 03:13:23 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_printmap(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putchar(map[i]);
		i++;
	}
}
