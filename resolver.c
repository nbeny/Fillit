/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:32:44 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/02 01:01:24 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void recursive(char **tetri, char **map, int maxtetri, int n_tetri)
{
	int x_map;
	int y_map;

	y_map = -1;
	while (++y_map < SIZE)
	{
		x_map = -1;
		while (++x_map < SIZE)
		{
			if (add_tetri(map, y_map, x_map, tetri[n_tetri]))
			{
				if ((n_tetri + 1) != maxtetri)
					recursive(tetri, map, maxtetri, (n_tetri + 1));
				else
					ft_print_map(map, SIZE);
				delete_tetri(map, what_is_tetri(tetri[n_tetri]), SIZE);
			}
		}
	}
}
