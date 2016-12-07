/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:41:14 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/07 05:42:40 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_free_tend(t_end *end)
{
	if (end)
	{
		free(end);
		end = NULL;
	}
}

int			main(int argc, char **argv)
{
	t_end	*end;
	t_list	*listt;

	end = (t_end *)malloc(sizeof(t_end));
	end->result = ft_check(argv);
	if (end->result == 0 || argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	listt = ft_stockt(argv);
	end->nb_tetri = ft_nbtminos(listt);
	if (end->nb_tetri > 26)
	{
		write(1, "error\n", 6);
		return (0);
	}
	end->result = ft_tabt(listt);
	ft_resolv(listt, end);
	ft_free_tend(end);
	return (0);
}
