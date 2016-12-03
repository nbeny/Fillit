/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillTmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:25:00 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/02 01:01:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_var	*ft_looktetri(t_list *list, t_var *var, t_pos *pos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (list->tab[var->j])
	{
		var->i = 0;
		while (list->tab[var->j][var->i])
		{
			if (list->tab[var->j][var->i] >= 'A' && list->tab[var->j][var->i] <= 'Z')
			{
				pos->pos[j][i] = var->j;
				i++;
				pos->pos[j][i] = var->i;
				j++;
				i = 0;
			}
			var->i++;
		}
		var->j++;
	}
	return (var);
}

int		ft_tchecinser(t_pos *pos, char **map)
{
	if (map[pos->y + (pos->pos[1][0] - pos->pos[0][0])]\
		[pos->x + (pos->pos[1][1] - pos->pos[0][1])] != '.')
		return (0);
	if (map[pos->y + (pos->pos[2][0] - pos->pos[0][0])]\
		[pos->x + (pos->pos[2][1] - pos->pos[0][1])] != '.')
		return (0);
	if (map[pos->y + (pos->pos[3][0] - pos->pos[0][0])]\
		[pos->x + (pos->pos[3][1] - pos->pos[0][1])] != '.')
		return (0);
	if (map[pos->y + (pos->pos[4][0] - pos->pos[0][0])]\
		[pos->x + (pos->pos[4][1] - pos->pos[0][1])] != '.')
		return (0);
	return (1);
}

char	**ft_printtetri(t_pos *pos, char **map, t_var *var)
{
	var->l = 65;
	map[pos->y + (pos->pos[1][0] - pos->pos[0][0])]					\
		[pos->x + (pos->pos[1][1] - pos->pos[0][1])] = (char)(var->l);
	map[pos->y + (pos->pos[2][0] - pos->pos[0][0])] \
		[pos->x + (pos->pos[2][1] - pos->pos[0][1])] = (char)(var->l);
	map[pos->y + (pos->pos[3][0] - pos->pos[0][0])] \
		[pos->x + (pos->pos[3][1] - pos->pos[0][1])] = (char)(var->l);
	map[pos->y + (pos->pos[4][0] - pos->pos[0][0])] \
		[pos->x + (pos->pos[4][1] - pos->pos[0][1])] = (char)(var->l);
	var->l++;
	return (map);
}

char	**ft_lookmap(char **map)
{
	t_pos *pos;
	t_var *var;

	var = (t_var *)malloc(sizeof(t_pos));
	var = init_tvar(var);
	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->y = 0;
	while (map[pos->y])
	{
		pos->x = 0;
		while (map[pos->y][pos->x])
		{
			if (map[pos->y][pos->x] == '.')
			{
				if (ft_tchecinser(pos, map) == 1)
				{
					map = ft_printtetri(pos, map, var);
					return (map);
				}
			}
			pos->x++;
		}
		pos->y++;
	}
	return (map);
}
