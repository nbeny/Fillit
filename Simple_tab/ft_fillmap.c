/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:02:55 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/02 21:13:41 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_pointc(char *str, int mlen)
{
	int	point;
	int	save;

	point = 0;
	while (str[point] == '.')
		point++;	
	save = point;
	if (save == 3)
		point = mlen - 1;
	if (save == 1)
		point = mlen - 3;
	if (save == 2)
		point = mlen - 2;
	return (point);
}

int		ft_skipp(char *str, int j)
{
	while (str[j] == '.')
		j++;
	j--;
	return (j);
}

int		ft_fillmapcheck(t_list *tlist, char *map, int mlen, int i)
{
	int		j;
	int		jump;
	char	*tminos;

	j = 0;
	tminos = tlist->tab;
	while (tminos[j])
	{
		jump = 0;
		if (tminos[j] != '.' && map[i] != '.')
			return (0);
		if (tminos[j] == '.')
		{
			i = i + ft_pointc(&tminos[j], mlen);
			j = ft_skipp(tminos, j);
		}
		i++;
		j++;
	}
	return (1);
}

char	*ft_fillmap(t_list *tlist, char *map, int mlen)
{
	int		i;
	int		j;
	char	*tminos;

	i = 0;
	j = 0;
	tminos = tlist->tab;
	printf("%s\n", tminos);
	while (map[i])
	{
		if ((ft_fillmapcheck(tlist, map, mlen, i)) == 1)
			while (tminos[j])
			{
				if (map[i] == '\n' && tminos[j] != '.')
					i++;
				if (tminos[j] != '.')
					map[i] = tminos[j];
				if (tminos[j] == '.')
				{
					i = i + ft_pointc(&tminos[j], mlen);
					j = ft_skipp(tminos, j);
				}
				i++;
				j++;
			}
		i++;
	}
	return (map);
}
