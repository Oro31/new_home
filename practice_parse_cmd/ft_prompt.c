#include "minishell.h"

int	ft_is_eof(char *line)
{
	if (!line)
	{
		g_status = 0;
		free(line);
		return (1);
	}
	return (0);
}

int	ft_prompt(t_cmd **cmd)
{
	char	**cmd_char;
	char	*line;

	line = readline("$>");
	if (ft_is_eof(line))
		return (1);
	g_status = 0;
	if (ft_strlen(line) > 0)
	{
		add_history(line);
		cmd_char = ft_cmdline_split(line);
		*cmd = ft_hadd_tolist_cmd(*cmd, cmd_char, 0, 0);
	}
	return (0);
}
