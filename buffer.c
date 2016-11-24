
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:04:45 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/24 01:25:48 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
t_var	*init_tvar(t_var *var)
{
	var->a = 0;
	var->b = 0;
	var->i = 0;
	var->j = 0;
	var->k = 0;
	var->l = 0;
	return (var);
}

t_buff	*init_tbuff(t_buff *buff, char **av)
{
	buff->fd = open(av[1], O_RDONLY);
	return (buff);
}

int		**ft_reader(int ac, char **av)
{
	t_var	*var;
	t_buff	*buff;
	int		**tab;

	buff = (t_buff *)malloc(sizeof(t_buff));
	var = (t_var *)malloc(sizeof(t_var));
	buff = init_tbuff(buff, av);
	var = init_tvar(var);
	tab = (int **)malloc(sizeof(int *) * 50);
	while (var->l < 49)
	{
		tab[var->l] = (int *)malloc(sizeof(int) * 4);
		var->l++;
	}
	tab[var->l] = NULL;
	while (read(buff->fd, buff->buff, 21) != 0)
	{
		var->k = 0;
		while (var->k < 21)
		{
			if (buff->buff[var->k] == '.')
			{
				tab[var->j][var->i] = 0;
				printf("%d ", tab[var->j][var->i]);fflush(stdout);
				var->i++;
			}
			if (buff->buff[var->k] == '#')
			{
				tab[var->j][var->i] = 1;
				printf("%d ", tab[var->j][var->i]);
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
	}
	return (tab);
}

int		main(int ac, char **av)
{
	ft_reader(ac, av);
	return(0);
}
