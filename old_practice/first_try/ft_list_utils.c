/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:57:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/11/30 02:48:33 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_size_listr(t_estr *list)
{
	t_estr	*tmp;
	int		i;

	if (list == NULL)
		return (0);
	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	return (i);
}

void	ft_print_list(t_estr *str)
{
	t_estr	*tmp;

	if (str != NULL)
	{
		tmp = str;
		while (tmp)
		{
			ft_print_str(tmp->str);
			tmp = tmp->nxt;
		}
	}
}

t_estr	*ft_copy_listr(t_estr *listr)
{
	t_estr	*tmp;
	t_estr	*copy;

	if (listr == NULL)
		return (NULL);
	copy = NULL;
	tmp = listr;
	while (tmp)
	{
		copy = ft_eadd_tolistr(copy, tmp->str);
		tmp = tmp->nxt;
	}
	return (copy);
}
