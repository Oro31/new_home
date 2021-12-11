/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:24:57 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/06 15:45:47 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s1_sleep(pid_t ps)
{
	int		ret;

	ret = kill(ps, SIGUSR1);
	if (ret == -1)
	{
		perror("Erreur lors de l'envoie du signal ");
		exit(EXIT_FAILURE);
	}
	usleep(MS);
}

void	s2_sleep(pid_t ps)
{
	int		ret;

	ret = kill(ps, SIGUSR2);
	if (ret == -1)
	{
		perror("Erreur lors de l'envoie du signal ");
		exit(EXIT_FAILURE);
	}
	usleep(MS);
}

void	s2_nosleep(pid_t ps)
{
	int		ret;

	ret = kill(ps, SIGUSR2);
	if (ret == -1)
	{
		perror("Erreur lors de l'envoie du signal ");
		exit(EXIT_FAILURE);
	}
}

void	send_message(pid_t ps, char *str)
{
	int		c;
	int		b;
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		c = (int)str[i];
		j = -1;
		while (++j < 8)
		{
			b = c % 2;
			c = c / 2;
			if (b == 1)
				s1_sleep(ps);
			else
				s2_sleep(ps);
		}
		s1_sleep(ps);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pidserveur;
	int		i;

	if (argc != 3)
	{
		ft_printf("Wrong arguments\n");
		exit(EXIT_FAILURE);
	}
	pidserveur = ft_atoi(argv[1]);
	s1_sleep(pidserveur);
	i = -1;
	while (argv[2][++i])
		s1_sleep(pidserveur);
	s2_sleep(pidserveur);
	send_message(pidserveur, argv[2]);
	s2_nosleep(pidserveur);
	return (0);
}
