/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:22:10 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/05 19:38:21 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tabt(t_list *alist)
{
	int		i;
	int		nb;

	nb = ft_nbtminos(alist);
	i = 0;
	if (nb > 2)
	{
		while (i * i < nb)
			i++;
		return (i * 2);
	}
	if (nb == 2)
		return (3);
	if (nb == 1)
		return (2);
	return (0);
}
