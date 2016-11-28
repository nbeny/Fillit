/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:04:45 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/28 17:51:16 by nbeny            ###   ########.fr       */
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
	var->k = 0;
	var->a = 0;
	var->i = 0;
	while (buff->buff[var->k] != '#')
		var->k++;
	while (var->k < 20 && var->a < 4)
	{
		if (buff->buff[var->k] == '.')
		{
			list->tab[var->i] = '.';
			var->i++;
		}
		if (buff->buff[var->k] == '#')
		{
			list->tab[var->i] = ('A' + var->l);
			var->i++;
			var->a++;
		}
		var->k++;
	list->tab[var->i] = '\0';
	var->l++;
	return (list);
}

t_list		*ft_reader(char **av)
{
	t_list	*save;
	t_list	*list;
	t_var	*var;
	t_buff	*buff;

	buff = (t_buff *)malloc(sizeof(t_buff));
	var = (t_var *)malloc(sizeof(t_var));
	buff = init_tbuff(buff, av);
	var = init_tvar(var);
	if (av)
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

	(void)ac;
	y = 0;
	alist =	ft_reader(av);
	while (alist)
	{
			printf("%s\n", alist->tab);
			alist = alist->next;
	}
	return(0);
}
