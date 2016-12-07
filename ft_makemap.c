/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:28:42 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/07 04:11:28 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_makemap(t_end *end)
{
	char	*map;
	int		len;
	int		i;

	i = 0;
	len = (end->result * end->result) + end->result + 1;
	map = (char *)malloc(sizeof(char) * len);
	while (len > 1)
	{
		map[i] = '.';
		if (((i + 1) % (end->result + 1)) == 0)
			map[i] = '\n';
		len--;
		i++;
	}
	map[i] = '\0';
	return (map);
}
