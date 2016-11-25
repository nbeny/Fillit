/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:04:45 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/25 18:18:01 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_var		*init_tvar(t_var *var)
{
	var->a = 0;
	var->i = 0;
	var->j = 0;
	var->k = 0;
	var->l = 0;
	return (var);
}

t_buff		*init_tbuff(t_buff *buff, char **av)
{
	buff->fd = open(av[1], O_RDONLY);
	return (buff);
}

t_list		*init_tab(t_list *list, t_var *var, t_buff *buff)
{
		var->j = 0;
		var->k = 0;
		while (var->k < 20)
		{
			if (buff->buff[var->k] == '.')
			{
				list->tab[var->j][var->i] = 0;
				printf("%d ", list->tab[var->j][var->i]);fflush(stdout);
				var->i++;
			}
			if (buff->buff[var->k] == '#')
			{
				list->tab[var->j][var->i] = 1;
				printf("%d ", list->tab[var->j][var->i]);fflush(stdout);
				var->i++;
			}
			if (buff->buff[var->k] == '\n')
			{
				var->i = 0;
				var->j++;
				printf("\n");fflush(stdout);
			}
			var->k++;
		}
		return (list);
}

t_list		*ft_reader(int ac, char **av)
{
	t_list	*save;
	t_list	*list;
	t_var	*var;
	t_buff	*buff;

	buff = (t_buff *)malloc(sizeof(t_buff));
	var = (t_var *)malloc(sizeof(t_var));
	buff = init_tbuff(buff, av);
	var = init_tvar(var);
	if (list && av)
	{
		list = (t_list *)malloc(sizeof(t_list));
		save = list;
		while (read(buff->fd, buff->buff, 21) != 0)
		{
			list = init_tab(list, var, buff);
			list->next = (t_list *)malloc(sizeof(t_list));
			list = list->next;
		}
		list = NULL;
	}
	return (save);
}

int		main(int ac, char **av)
{
	t_list	*alist;
	int y;
	int t;
	int r;

	r = 1;
	y = 0;
	alist =	ft_reader(ac, av);
	while (alist)
	{
		t = 0;
		while (t < 4)
		{
			y = 0;
			while (y < 4)
			{
				printf("%d : %d\n",r , alist->tab[t][y]);
				y++;
				r++;
			}
			t++;
		}
		alist = alist->next;
	}
	return(0);
}
