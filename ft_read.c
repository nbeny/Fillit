/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:17 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/21 17:02:30 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_strlen(int fd)
{
	int j;

	j = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (read(fd, &buffer, 1) == '\n')
			j++;
	}
	return (j);
}


int		**ft_read(int argc, char **argv)
{
	char	buffer;
	int		**tab;
	int		fd;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	fd = open(argv[1], O_RDONLY);
	tab = (int **)malloc(sizeof(int *) * ft_strlen(fd));
	while (tab[j])
	{
		tab[j] = (int *)malloc(sizeof(int) * 4);
		j++;
	}
	while (read(fd, &buffer, 1) != 0)
	{
		if (read(fd, &buffer, 1) == '#')
			tab[j][i] = k;
		if (read(fd, &buffer, 1) == '.')
			tab[j][i] = 0;
		if (read(fd, &buffer, 1) == '\n')
			j++;
		if (j % 4 == 0)
			k++;
		i++;
	}
	return (tab);
}

int		main()
