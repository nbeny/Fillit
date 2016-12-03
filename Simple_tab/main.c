/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:41:14 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/03 17:31:30 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		result;
	t_list	*listt;
	char	*map;

	result = ft_check(argv);
	listt = ft_stockt(argv);
	if (result == 0 || argc != 2 || ft_nbtminos(listt) > 26)
	{
		write(1, "error\n", 6);
		return (0);
	}
	result = 5;
	map = ft_makemap(result);
	while (listt)
	{
		map = ft_fillmap(listt, map, result);
		listt = listt->next;
	}
	printf("%s", map);
	return (0);
}
