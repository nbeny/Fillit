/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcheci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:51:44 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/30 21:15:33 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		tchec_i(t_list *list, t_buff *buff, t_var *var)
{
	int i;
	int var_k;

	i = 0;
	var_k = var->k;
	while (buff->buff[var->k] < 20)
	{
		if (buff->buff[var->k] == '.' && i < 4)
		{
			var->k = var->k + 5;
			i++;
		}
		if (i == 4)
		{
			var->k = var_k;
			return (1);
		}
	}
	var->k = var_k;
	return (0);
}
