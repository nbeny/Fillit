/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:28:42 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/01 04:36:44 by nbeny            ###   ########.fr       */
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
	while (map[j])
	{
		if (!(map[j] = (char *)malloc(sizeof(char) * (tminos + 1))))
			return (NULL);
		i = 0;
		while (map[j][i])
		{
			if (i < tminos)
				map[j][i] = '.';
			if (i == tminos)
				map[j][i] = '\0';
			i++;
		}
		j++;
	}
	map[j] = NULL;
	return (map);
}
