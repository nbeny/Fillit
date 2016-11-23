/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:04:45 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/23 15:55:32 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	**ft_reader(int **tab, int size)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	buffer;

	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buffer, 21) != 0)
	{
		k = 0;
		while (buffer[k])
		{
			if (buffer[k] == '.')
				tab
		}
	}
}

void		buffer(t_list **alst, void (*f)(void **, size_t))
{
	t_list	*lst;
	t_list	*new;
	t_list	*nxtlst;

	lst = (*alst);
	nxtlst = lst->next;
	new = ft_lstnew(lst->tab, lst->size);
	while (lst)
	{
		f(lst->new);
		lst = nxtlst;
	}
}
