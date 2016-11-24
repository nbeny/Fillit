/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:04:45 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/24 20:50:48 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_var		*init_tvar(t_var *var)
{
	var->a = 0;
	var->b = 0;
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

t_list		*init_tlist(t_var *var, t_list *list)
{
	t_list *save;

	list = (t_list *)malloc(sizeof(t_list));
	save = list;
	list->tab = (int **)malloc (sizeof(int *) * 5);
	while (var->l < 4)
	{
		list->tab[var->l] = (int *)malloc(sizeof(int) * 4);
		var->l++;
	}
	list->tab[var->l] = NULL;

	return (save);
}

t_list		**ft_reader(int ac, char **av)
{
	t_list	**alist;
	t_list	*list;
	t_var	*var;
	t_buff	*buff;

	alist = (t_list **)malloc(sizeof(t_list *));
	*alist = (t_list *)malloc(sizeof(t_list ));
	buff = (t_buff *)malloc(sizeof(t_buff));
	var = (t_var *)malloc(sizeof(t_var));
	buff = init_tbuff(buff, av);

	list = init_tlist(var, list);
	while (read(buff->fd, buff->buff, 21) != 0)
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
				printf("%d ", list->tab[var->j][var->i]);
				var->i++;
			}
			if (buff->buff[var->k] == '\n')
			{
				var->i = 0;
				var->j++;
				printf("\n");
			}
			var->k++;
		}
//		(*alist) = list;
		list->next = init_tlist(var, list);
		list = list->next;
	}
	return (alist);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	ft_reader(ac, av);
	return(0);
}
