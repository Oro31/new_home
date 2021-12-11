#include "minishell.h"

int	ft_parse_rdline(char *line)
{
	if (!line)
		return (1);
	else if (ft_strncomp(line, "exit", 4) == 0)
		return (1);
	return (0);
}

int	ft_prompt(t_estr **ppt)
{
	char	*str;
	
	str = readline("$>");
	if (ft_parse_rdline(str))
	{
		free(str);
		return (1);
	}
	if (ft_strlen(str) > 0)
	{
		add_history(str);
		*ppt = ft_hadd_tolistr(*ppt, str);
	}
	return (0);
}
