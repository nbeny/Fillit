/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbtminos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:33:16 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/02 15:59:17 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nbtminos(t_list *alist)
{
	int		nb;
	t_list	*save;

	nb = 0;
	save = alist;
	while (alist)
	{
		nb++;
		alist = alist->next;
	}
	alist = save;
	printf("%d\n", nb);
	return (nb);
}
