#include "minishell.h"

int	g_status;

static char	*ft_add_char(char *str, char c)
{
	char	*tmp;
	int		i;

	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	i = -1;
	while (++i < ft_strlen(str))
		tmp[i] = str[i];
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}

static void	sig_handler(int signum)
{
	if (signum == SIGQUIT)
		g_status = 1;
	else if (signum == SIGINT)
		g_status = 2;
}

int	main(void)
{
	struct sigaction	action;
	char				*str;
	char				c;
	int					ret;

	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	str = NULL;
	str = malloc(sizeof(char));
	ret = 1;
	g_status = 0;
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	ft_print_str("$>");
	ret = 1;
	while (ret > 0)
	{
		while (c != '\n' && g_status != 2)
		{
			ret = read(0, &c, 1);
			if (c == 'q')
				g_status = 2;
			else
				str = ft_add_char(str, c);
		}
		printf("line = %s", str);
		ret = 0;
		/*if (g_status == 2)
		{
			ft_print_str("\n$>");
			g_status = 1;
			c = '\n';
		}
		else if (c == '\n' && g_status != 1)
		{
			printf("str = %s\n", str);
			ft_print_str("\n$>");
			free(str);
		}
		else if (c && g_status != 1)
			str = ft_add_char(str, c);
		else if (!c && g_status == 0)
			ret = 0;
		else
			g_status = 0;*/
	}
	return (0);
}
