/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:10:26 by rvalton           #+#    #+#             */
/*   Updated: 2021/11/30 02:59:01 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_str(char *str)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncomp(char *str, char *comp, int n)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (!comp)
			return (-99);
		else
			return (0 - comp[0]);
	}
	else if (!comp)
		return (str[0]);
	if (ft_strlen(str) < n)
		return (-99);
	while (str[i] && comp[i] && str[i] == comp[i] && i < n)
		i++;
	return (str[i] - comp[i]);
}
