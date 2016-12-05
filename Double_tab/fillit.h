/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:08:19 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/05 18:55:53 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_buff
{
	int		fd;
	char	buff[21];
}				t_buff;
typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;
typedef struct	s_var
{
	int a;
	int i;
	int j;
	int b;
	int l;
}				t_var;
typedef struct	s_list
{
	char	tab[4][5];
	int		pos[5][2];
	int		n_tetri;
	struct s_list	*next;
}				t_list;
t_pos			*init_tpos(t_pos *pos);
t_var			*init_tvar(t_var *var);
t_buff			*init_tbuff(t_buff *buff, char **av);
t_list			*init_tab(t_list *list, t_var *var, t_buff *buff);
int				ft_check(char **argv);
int				main(int argc, char **argv);
t_list			*ft_stockt(char **av);
char			**ft_makemap(int tminos);
int				ft_tabt(t_list *alist);
t_pos			*ft_looktetri(t_list *list, t_var *var, t_pos *pos);
int				ft_tchecinser(t_pos *pos, char **map);
char			**ft_printtetri(char **map, t_list *list);
void			ft_lookmap(char **map);
#endif


