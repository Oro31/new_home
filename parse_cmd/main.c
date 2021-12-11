#include "minishell.h"

static void	ft_handler(int signum)
{
	if (signum == SIGQUIT)
	{
		if (g_status == 1)
			g_status = 2;
		else
			g_status = 1;
	}
	else if (SIGINT)
	{
		ft_print_str("\n$>");
		if (g_status == 1)
			g_status = 2;
		else
			g_status = 1;
	}
}

int	main(void)
{
	struct sigaction	action;
	char				**str;
	int					ret;
	int					i;

	action.sa_handler = ft_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	str = NULL;
	ret = 0;
	g_status = 0;
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	while (!ret || g_status)
	{
		ret = ft_prompt(&str);
		i = -1;
		while (str && str[++i])
		{
			ft_print_str(str[i]);
			printf("\n");
//			free(str[i]);
		}
//		free(str);
	}
//	free(str);
	return (0);
}
