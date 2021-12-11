/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:36:14 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/06 15:37:36 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_start;

static void	ft_init(t_vars *vars)
{
	vars->str = malloc(sizeof(char));
	vars->str[0] = '\0';
	vars->len = 0;
	vars->constlen = 11;
	vars->cpt = 0;
}

static void	ft_hndlr_end(t_vars *vars)
{
	ft_print(vars->str, vars->constlen);
	vars->cpt = 0;
}

static void	hndlr_bis(int signum, t_vars *vars)
{
	if (signum == SIGUSR1 && vars->cpt == 1)
	{
		vars->len++;
	}
	else if (signum == SIGUSR2 && vars->cpt == 1)
	{
		vars->constlen = vars->len;
		vars->cpt = 2;
	}
	else if (signum == SIGUSR1 && vars->cpt > 1 && vars->cpt < 10
		&& vars->len > 0)
	{
		vars->octet[vars->cpt - 2] = 1;
		vars->cpt++;
	}
	else if (signum == SIGUSR2 && vars->cpt > 1 && vars->cpt < 10
		&& vars->len > 0)
	{
		vars->octet[vars->cpt - 2] = 0;
		vars->cpt++;
	}
}

static void	handler(int signum)
{
	static t_vars	vars;
	int				i;

	if (g_start)
		ft_init(&vars);
	i = -1;
	if (signum == SIGUSR1 && vars.cpt == 0)
	{
		g_start = 0;
		vars.str = ft_reset_str(vars.str);
		vars.cpt = 1;
	}
	else if (signum == SIGUSR1 && vars.cpt == 10)
	{
		vars.str = ft_putchar(vars.octet, vars.str);
		while (++i < 8)
			vars.octet[i] = 0;
		vars.len--;
		vars.cpt = 2;
	}
	else if (signum == SIGUSR2 && vars.len == 0 && vars.cpt == 2)
		ft_hndlr_end(&vars);
	else
		hndlr_bis(signum, &vars);
}

int	main(void)
{
	struct sigaction	action;

	g_start = 1;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
	{
		perror("Erreur lors du positionnement ");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &action, NULL) == -1)
	{
		perror("Erreur lors du positionnement ");
		exit(EXIT_FAILURE);
	}
	ft_printf("Pret a recevoir des signaux. Mon PID : %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
