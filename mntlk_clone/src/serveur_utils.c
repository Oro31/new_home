/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:33:46 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/06 15:37:55 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int d, int p)
{
	int	i;
	int	res;

	res = 1;
	i = p;
	while (i > 0)
	{
		res = res * d;
		i--;
	}
	return (res);
}

void	ft_print(char *str, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

char	*ft_realloc(char res, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	tmp[i + 1] = '\0';
	tmp[i] = res;
	while (--i >= 0)
		tmp[i] = str[i];
	free(str);
	return (tmp);
}

char	*ft_putchar(int *octet, char *str)
{
	int		i;
	int		res;
	char	c;

	c = '\0';
	res = 0;
	i = -1;
	while (++i < 8)
	{
		res = res + (octet[i] * ft_pow(2, i));
	}
	c = res;
	str = ft_realloc(c, str);
	return (str);
}

char	*ft_reset_str(char *s)
{
	char	*str;

	str = malloc(sizeof(char));
	str[0] = '\0';
	free(s);
	return (str);
}
