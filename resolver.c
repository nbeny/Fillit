/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:32:44 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/03 18:09:03 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void recursive(t_list *list, char *map, int maxtetri, int mlen)
{
	int x;

	x = -1;
	while (++x < SIZE)
	{
		if (x % mlen == 0)
			++x;
		if (ft_fillmap(t_list *list, char *map, int mlen))
		{
			if ((n_tetri + 1) != count_list(list))
				recursive(list, map, maxtetri, mlen);
			else
				ft_print_map(map, SIZE);
			delete_tetri(map, what_is_tetri(tetri[n_tetri]), SIZE);
		}
	}
}
