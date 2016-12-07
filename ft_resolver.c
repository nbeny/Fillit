/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:10:10 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/07 05:36:46 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_sleep(char *map, t_end *end)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == ('A' + end->nb_tetri - 1))
			count++;
		if (count > 4)
			return (0);
		i++;
	}
	return (1);
}

static void		ft_resolver(t_list *list, char *map, t_end *end, int i)
{
	while (map[++i])
	{
		if (ft_fillmap(list, map, end, i) == 1)
		{
			if (list->next)
				ft_resolver(list->next, map, end, -1);
			if (!list->next && ft_sleep(map, end) == 1)
				ft_printmap(map);
			ft_deletetetri(list, map);
		}
	}
}

static int		ft_checkmap(char *map, t_end *end)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == ('A' + end->nb_tetri - 1))
			return (1);
		i++;
	}
	return (0);
}

void			ft_resolv(t_list *list, t_end *end)
{
	char	*map;

	while (end->result != -1)
	{
		map = ft_makemap(end);
		ft_resolver(list, map, end, -1);
		end->result++;
		if (ft_checkmap(map, end) == 1)
			end->result = -1;
		free(map);
	}
}
