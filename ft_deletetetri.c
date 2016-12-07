/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletetetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:04:12 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/07 05:04:26 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_deletetetri(t_list *list, char *map)
{
	int	j;
	int	l;

	j = 0;
	l = list->tab[0];
	if (list->next)
	{
		if (list->tab[0] != 'A')
			l = list->tab[0] - 1;
		while (map[j])
		{
			if (map[j] == list->tab[0])
				map[j] = '.';
			j++;
		}
	}
}
