/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:35:50 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/06 15:40:42 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int		res;
	int		i;
	int		j;

	res = 0;
	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (i > 0)
	{
		i--;
		res = res + (int)((str[i] - 48) * ft_pow(10, j));
		j++;
	}
	return (res);
}

void	ft_putnbr(int d)
{
	char	c;
	int		res;
	int		i;

	res = d;
	i = 0;
	while (res >= 10)
	{
		res = res / 10;
		i++;
	}
	i++;
	res = d;
	while (i > 0)
	{
		i--;
		c = (res % ft_pow(10, i + 1) / ft_pow(10, i)) + 48;
		write(1, &c, 1);
	}
}

void	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		d;

	va_start(ap, format);
	i = -1;
	while (format[++i])
	{
		while (format[i] != '%' && format[i])
		{
			write(1, &format[i], 1);
			i++;
		}
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			d = va_arg(ap, int);
			ft_putnbr(d);
			i++;
		}
	}
	va_end(ap);
}
