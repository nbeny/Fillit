/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:28:42 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/05 13:19:15 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_makemap(int tminos)
{
	char	**map;
	int		j;
	int 	i;

	j = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (tminos + 1))))
		return (NULL);
	while (j < tminos)
	{
		if (!(map[j] = (char *)malloc(sizeof(char) * (tminos + 1))))
			return (NULL);
		j++;
	}
	j = 0;
	while (j <= tminos)
	{
		i = 0;
		while (i <= tminos)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}
