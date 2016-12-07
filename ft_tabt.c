/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:22:10 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/07 08:20:52 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tabt(t_list *alist)
{
	int		nb;

	nb = ft_nbtminos(alist);
	if (nb == 26 || nb == 27)
		return (11);
	if (nb == 21 || nb == 22 || nb == 23 || nb == 24 || nb == 25)
		return (10);
	if (nb == 17 || nb == 18 || nb == 19 || nb == 20)
		return (9);
	if (nb == 13 || nb == 14 || nb == 15 || nb == 16)
		return (8);
	if (nb == 10 || nb == 11 || nb == 12)
		return (7);
	if (nb == 7 || nb == 8 || nb == 9)
		return (6);
	if (nb == 5 || nb == 6)
		return (5);
	if (nb == 2)
		return (3);
	if (nb == 1)
		return (2);
	return (0);
}
