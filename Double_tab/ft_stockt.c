#include "fillit.h"

t_var		*init_tvar(t_var *var)
{
	var->a = 0;
	var->i = 0;
	var->j = 0;
	var->b = 0;
	var->l = 0;
	return (var);
}

t_buff		*init_tbuff(t_buff *buff, char **av)
{
	buff->fd = open(av[1], O_RDONLY);
	return (buff);
}

t_list		*init_tab(t_list *list, t_var *var, t_buff *buff)
{
	var->b = 0;
	var->i = 0;
	var->j = 0;
	while (var->b < 20)
	{
		if (buff->buff[var->b] == '.')
		{
			list->tab[var->j][var->i] = '.';
			var->i++;
		}
		if (buff->buff[var->b] == '#')
		{
			list->tab[var->j][var->i] = '#';
			var->i++;
		}
		if (buff->buff[var->b] == '\n')
		{
			list->tab[var->j][var->i] = '\0';
			var->i = 0;
			var->j++;
		}
		var->b++;
	}
	list->n_tetri = var->l++;
	return (list);
}

t_list		*ft_stockt(char **av)
{
	t_list	*save;
	t_list	*list;
	t_list	*beflist;
	t_var	*var;
	t_buff	*buff;

	buff = (t_buff *)malloc(sizeof(t_buff));
	var = (t_var *)malloc(sizeof(t_var));
	buff = init_tbuff(buff, av);
	var = init_tvar(var);
	list = (t_list *)malloc(sizeof(t_list));
	save = list;
	while (read(buff->fd, buff->buff, 21) != 0)
	{
		list = init_tab(list, var, buff);
		beflist = list;
		list->next = (t_list *)malloc(sizeof(t_list));
		list = list->next;
	}
	free(list);
	list = NULL;
	beflist->next = NULL;
	free(var);
	free(buff);
	return (save);
}
