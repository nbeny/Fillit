/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:14:09 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/06 23:18:38 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_valid(int fd)
{
	char	buff[21];
	int		hash;
	int		i;

	while (read(fd, buff, 21))
	{
		i = 0;
		hash = 0;
		while (i < 20)
		{
			if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
				return (0);
			if (((i + 1) % 5 != 0 && buff[i] == '\n') ||
					((i + 1) % 5 == 0 && buff[i] != '\n'))
				return (0);
			if (buff[i] == '#')
				hash++;
			i++;
		}
		if (hash != 4)
			return (0);
	}
	return (1);
}

static int		ft_tminos(int fd)
{
	int		i;
	int		save;
	char	buff[21];

	while (read(fd, buff, 21))
	{
		save = 0;
		i = 0;
		while (i < 20)
		{
			if (buff[i] == '#')
			{
				save = i;
				while (buff[i++] != '\n' && buff[i])
					if (buff[i] == '.' && buff[i + 1] == '#')
						return (0);
				i = save;
			}
			if (buff[i] == '#' && (i - save) > 4)
				return (0);
			i++;
		}
	}
	return (1);
}

static int		ft_tminosbis(int fd)
{
	int		i;
	char	buff[21];
	int		connect;
	int		hash;

	while (read(fd, buff, 21))
	{
		hash = 0;
		i = -1;
		while (i++ < 20 && hash < 4)
		{
			connect = 0;
			while (buff[i] != '\n')
			{
				if (buff[i] == '#')
					hash++;
				if (buff[i] == '#' && buff[i + 5] == '#')
					connect = 1;
				i++;
			}
			if (connect == 0 && hash != 0 && hash != 4)
				return (0);
		}
	}
	return (1);
}

static int		ft_checkend(int fd)
{
	int		i;
	int		ncount;
	char	buff[800];

	i = 0;
	ncount = 1;
	read(fd, buff, 800);
	while (buff[i])
	{
		if (buff[i] == '\n')
			ncount++;
		if ((i + 1) % 21 == 0 && (buff[i] != '\0' && buff[i] != '\n'))
			return (0);
		i++;
	}
	if (buff[i - 2] == '\n' || ncount % 5 != 0)
		return (0);
	return (1);
}

int				ft_check(char **argv)
{
	if (!argv[1] || !open(argv[1], O_RDONLY))
		return (0);
	if (ft_valid(open(argv[1], O_RDONLY)) == 0 ||
		ft_tminos(open(argv[1], O_RDONLY)) == 0 ||
		ft_tminosbis(open(argv[1], O_RDONLY)) == 0 ||
		ft_checkend(open(argv[1], O_RDONLY)) == 0)
		return (0);
	return (1);
}
