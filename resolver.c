/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:03:39 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/28 16:19:19 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>



const t_data	g_data[19] = {
		{ "###...#.........", 3 },
		{ ".#...#..##......", 2 },
		{ "#...###.........", 3 },
		{ "##..#...#.......", 2 },
		{ "###.#...........", 3 },
		{ "##...#...#......", 2 },
		{ "..#.###.........", 3 },
		{ "#...#...##......", 2 },
		{ "###..#..........", 3 },
		{ ".#..##...#......", 2 },
		{ ".#..###.........", 3 },
		{ "#...##..#.......", 2 },
		{ ".##.##..........", 2 },
		{ "#...##...#......", 2 },
		{ "##...##.........", 2 },
		{ ".#..##..#.......", 2 },
		{ "####............", 4 },
		{ "#...#...#...#...", 1 },
		{ "##..##..........", 2 }
};

t_list			*reodrer(t_list *list, t_data *var, t_var *var)
{
	list = init_tlist(char **av);
	while(list)
	{
		while (list->tab[var])
	}
}

int
