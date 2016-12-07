/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:02:55 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/07 04:19:22 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_pointc(char *str, t_end *end)
{
	int	point;
	int	save;

	point = 0;
	while (str[point] == '.')
		point++;
	save = point;
	if (save == 3)
		point = end->result - 1;
	if (save == 1)
		point = end->result - 3;
	if (save == 2)
		point = end->result - 2;
	return (point);
}

static int		ft_skipp(char *str, int j)
{
	while (str[j] == '.')
		j++;
	j--;
	return (j);
}

static int		ft_fillmapcheck(t_list *tlist, char *map, t_end *end, int i)
{
	int		j;
	int		jump;
	char	*tminos;

	j = 0;
	tminos = tlist->tab;
	if (!tminos)
		return (0);
	while (tminos[j])
	{
		jump = 0;
		if (tminos[j] != '.' && map[i] != '.')
			return (0);
		if (tminos[j] == '.')
		{
			i = i + ft_pointc(&tminos[j], end);
			j = ft_skipp(tminos, j);
		}
		i++;
		j++;
	}
	return (1);
}

int				ft_fillmap(t_list *tlist, char *map, t_end *end, int i)
{
	int		j;
	char	*tminos;

	j = 0;
	tminos = tlist->tab;
	if ((ft_fillmapcheck(tlist, map, end, i)) == 1)
		while (tminos[j])
		{
			if (map[i] == '\n' && tminos[j] != '.')
				i++;
			if (tminos[j] != '.')
				map[i] = tminos[j];
			if (tminos[j] == '.')
			{
				i = i + ft_pointc(&tminos[j], end);
				j = ft_skipp(tminos, j);
			}
			i++;
			j++;
		}
	else
		return (0);
	return (1);
}
