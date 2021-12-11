/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 08:18:49 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/05 10:09:38 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	**cmd_char;
	int		i;

	if (argc < 2)
		return (0);
	if (!ft_strlen(argv[1]))
		return (0);
	cmd_char = ft_cmdline_split(argv[1]);
	if (!cmd_char)
		return (0);
	i = -1;
	while (cmd_char[++i])
	{
		ft_print_str(cmd_char[i]);
		printf("\n");
	}
	return (0);
}
