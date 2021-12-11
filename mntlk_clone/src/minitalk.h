/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:54:36 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/06 15:33:33 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_SOURCE
# define MS 100
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_vars {
	char	*str;
	int		octet[8];
	int		len;
	int		constlen;
	int		cpt;
}				t_vars;

int		ft_pow(int d, int p);
void	ft_print(char *str, int size);
char	*ft_realloc(char res, char *str);
char	*ft_putchar(int *octet, char *str);
char	*ft_reset_str(char *s);

int		ft_atoi(char *str);
void	ft_putnbr(int d);
void	ft_printf(const char *format, ...);

#endif
