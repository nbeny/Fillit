/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:08:19 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/07 07:54:21 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_buff
{
	int		fd;
	char	buff[21];
}				t_buff;
typedef struct	s_var
{
	int a;
	int i;
	int k;
	int l;
}				t_var;
typedef struct	s_list
{
	char			tab[14];
	struct s_list	*next;
	struct s_list	*before;
}				t_list;
typedef struct	s_end
{
	int result;
	int nb_tetri;
}				t_end;
int				ft_check(char **argv);
int				main(int argc, char **argv);
t_list			*ft_stockt(char **av);
char			*ft_makemap(t_end *end);
int				ft_tabt(t_list *alist);
int				ft_fillmap(t_list *tlist, char *map, t_end *end, int i);
int				ft_nbtminos(t_list *alist);
void			ft_resolv(t_list *list, t_end *end);
void			ft_printmap(char *map);
void			ft_deletetetri(t_list *list, char *map);
#endif
