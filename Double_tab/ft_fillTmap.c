/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillTmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:25:00 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/05 18:55:24 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos	*ft_looktetri(t_list *list, t_var *var, t_pos *pos)
{
	int i;
	int j;
	int a;
	int b;

	i = 0;
	j = 0;
	a = 0;
	b = 0;
	while (list->tab[a])
	{
		b = 0;
		while (list->tab[a][b])
		{
			if (list->tab[a][b] == '#')
			{
				list->pos[j][i] = a;
				i++;
				list->pos[j][i] = b;
				j++;
				i = 0;
			}
			a++;
		}
		b++;
	}
	return (list);
}

int		ft_tchecinser(t_pos *pos, char **map)
{
	if (map[pos->y + (list->pos[1][0] - list->pos[0][0])]\
		[pos->x + (list->pos[1][1] - list->pos[0][1])] != '.')
		return (0);
	if (map[pos->y + (list->pos[2][0] - list->pos[0][0])]\
		[pos->x + (list->pos[2][1] - list->pos[0][1])] != '.')
		return (0);
	if (map[pos->y + (list->pos[3][0] - list->pos[0][0])]\
		[pos->x + (list->pos[3][1] - list->pos[0][1])] != '.')
		return (0);
	if (map[pos->y + (list->pos[4][0] - list->pos[0][0])]\
		[pos->x + (list->pos[4][1] - list->pos[0][1])] != '.')
		return (0);
	return (1);
}

char	**ft_printtetri(char **map, t_list *list, t_pos *pos)
{
	if (ft_tchecinser(pos, map) == 1)
	{
		map[pos->y + (list->pos[1][0] - list->pos[0][0])]	\
			[pos->x + (list->pos[1][1] - list->pos[0][1])] = 'A' + list->n_tetri;
		map[pos->y + (list->pos[2][0] - list->pos[0][0])] \
			[pos->x + (list->pos[2][1] - list->pos[0][1])] = 'A' + list->n_tetri;
		map[pos->y + (list->pos[3][0] - list->pos[0][0])] \
			[pos->x + (list->pos[3][1] - list->pos[0][1])] = 'A' + list->n_tetri;
		map[pos->y + (list->pos[4][0] - list->pos[0][0])] \
			[pos->x + (list->pos[4][1] - list->pos[0][1])] = 'A' + list->n_tetri;
	}
	return (map);
}

t_pos	*init_tpos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	return (pos);
}
