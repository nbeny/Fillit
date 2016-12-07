/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:56:37 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/06 20:04:22 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_var	*init_tvar(t_var *var)
{
	var->a = 0;
	var->i = 0;
	var->k = 0;
	var->l = 0;
	return (var);
}

static t_buff	*init_tbuff(t_buff *buff, char **av)
{
	buff->fd = open(av[1], O_RDONLY);
	return (buff);
}

static t_list	*init_tab(t_list *list, t_var *var, t_buff *buff)
{
	var->k = 0;
	var->i = 0;
	var->a = 0;
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
	}
	list->tab[var->i] = '\0';
	var->l++;
	return (list);
}

static void		ft_free_struct(t_var *var, t_buff *buff)
{
	if (var)
	{
		free(var);
		var = NULL;
	}
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
}

t_list			*ft_stockt(char **av)
{
	t_list	*save;
	t_list	*list;
	t_list	*beflist;
	t_var	*var;
	t_buff	*buff;

	buff = (t_buff *)malloc(sizeof(t_buff));
	var = (t_var *)malloc(sizeof(t_var));
	buff = init_tbuff(buff, av);
	var = init_tvar(var);
	list = (t_list *)malloc(sizeof(t_list));
	save = list;
	while (read(buff->fd, buff->buff, 21) != 0)
	{
		list = init_tab(list, var, buff);
		beflist = list;
		list->next = (t_list *)malloc(sizeof(t_list));
		list = list->next;
	}
	ft_free_struct(var, buff);
	free(list);
	list = NULL;
	beflist->next = NULL;
	return (save);
}
