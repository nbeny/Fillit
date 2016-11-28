/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:35:31 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/28 15:38:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_buff		*init_tbuff(t_buff *buff, char **av)
{
	buff->fd = open(av[1], O_RDONLY);
	return (buff);
}

t_var		*init_tvar(t_var *var)
{
	var->a = 0;
	var->i = 0;
	var->j = 0;
	var->k = 0;
	var->l = 0;
	return (var);
}

t_list		*init_tab_tlst(t_list *list, t_var *var, t_buff *buff)
{
	var->j = 0;
	var->k = 0;
	while (var->k < 20)
	{
		if (buff->buff[var->k] == '.')
		{
			list->tab[var->j][var->i] = '.';
			printf("%d ", list->tab[var->j][var->i]);fflush(stdout);
			var->i++;
		}
		if (buff->buff[var->k] == '#')
		{
			list->tab[var->j][var->i] = ('A' + var->l);
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
	var->l++;
	return (list);
}

t_pos		init_tpos(t_pos *pos)
{
	x = 0;
	y = 0;
	pos = 0;
	nblst = 0;
	return (pos);
}

t_list		*init_tlist(int ac, char **av)
{
	t_list	*save;
	t_list	*list;
	t_var	*var;
	t_buff	*buff;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	buff = (t_buff *)malloc(sizeof(t_buff));
	var = (t_var *)malloc(sizeof(t_var));
	list = (t_list *)malloc(sizeof(t_list));
	if (!data || !bull || !var || !list)
		return (NULL);
	data = init_tpos(data);
	buff = init_tbuff(buff, av);
	var = init_tvar(var);
	save = list;
	while (read(buff->fd, buff->buff, 21) != 0)
	{
		list = init_tab(list, var, buff);
		if(!(list->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		list = list->next;
		data->nblst++;
	}
	list = NULL;
	return (save);
}
