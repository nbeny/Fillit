/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:53:26 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/03 17:55:51 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countlist(t_list *alist)
{
	int		i;
	t_list	*save;

	i = 0;
	save = alist;
	while (alist)
	{
		i++;
		alist = alist->next;
	}
	alist = save;
	return (i);
}
