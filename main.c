/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:41:14 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/01 05:36:22 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		result;
	t_list	*listt;
	char	**map;
	int		tminos;
	int		i;

	i = 0;
	result = ft_check(av);
	if (result == 0 || ac != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	listt = ft_stockt(av);
	tminos = ft_tabt(listt);
	map = ft_makemap(tminos);
	while (listt)
	{
		map = ft_lookmap(map);
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
		listt = listt->next;
	}
	return (0);
}
