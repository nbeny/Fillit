/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:28:42 by kbagot            #+#    #+#             */
/*   Updated: 2016/11/30 12:47:45 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_makemap(int tminos)
{
	char	*map;
	int		len;
	int 	i;

	i = 0;
	len = (tminos * tminos) + tminos + 1;
	map = (char *)malloc(sizeof(char) * len);
	while (len > 1)
	{
		map[i] = '.';
		if (((i + 1) % (tminos + 1)) == 0)
			map[i] = '\n';
		len--;
		i++;
	}
	map[i] = '\0';
	return (map);
}
