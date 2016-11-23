/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:04:45 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/23 19:29:35 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	**ft_reader(t_list **alst)
{
	t_var a;
	int		fd;
	char	buffer[21];
	t_list	lst;

	lst = (*alst);
	lst = ft_lstnew(**tab, size);
	a.j = 0;
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buffer, 21) != 0)
	{
		a.k = 0;
		while (a.k < 20)
		{
			if (buffer[k] == '.')
					lst->tab[j][i++] = 0;
			if (buffer[k] == '#')
					lst->tab[j][i++] = 1;
			if (buffer[k] == '\n')
			{
				i = 0;
				j++;
			}
		}
		ft_lstadd(lst->tab, lst->size);

	}
	return (tab);
}
