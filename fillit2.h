/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:08:19 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/28 18:45:00 by nbeny            ###   ########.fr       */
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
	int j;
	int k;
	int l;
}				t_var;;
typedef struct	s_list
{
	char			tab[14];
	struct s_list	*next;
}				t_list;
//t_list			*ft_lstnew(void const **tab, size_t size);
//void			ft_lstdelone(t_list **alst, void (*del)(void **, size_t));
//void			ft_lstdel(t_list **alst, void (*del)(void **, size_t));
//void			ft_lstadd(t_list **alst, t_list *new);
//void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
//t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
