/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:36:10 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/04 03:26:34 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	ft_malloc_dblchar(char ***tmp, int size)
{
	tmp[0] = malloc(sizeof(char *) * size);
	if (!tmp[0])
	{
		ft_print_str("malloc failed \n");
		return (0);
	}
	tmp[0][size - 1] = NULL;
	return (1);
}
*/
int	ft_malloc_splchar(char **tmp, int size)
{
	*tmp = malloc(sizeof(char) * size);
	if (!*tmp)
	{
		printf("malloc failed \n");
		return (0);
	}
	(*tmp)[size - 1] = '\0';
	return (1);
}
