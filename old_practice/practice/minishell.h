#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_estr	t_estr;

typedef struct s_cmd	t_cmd;

struct	s_estr
{
	char	*str;
	t_estr	*nxt;
};

struct	s_cmd
{
	char	**argv;
	int		is_cmd_after_pipe;
};

int	ft_prompt(t_estr **ppt);

t_estr	*ft_hadd_tolistr(t_estr *list, char *str);
t_estr	*ft_eadd_tolistr(t_estr *list, char *str);
void	ft_free_listr(t_estr *listr);

int		ft_size_listr(t_estr *list);
void	ft_print_list(t_estr *str);

void	ft_print_str(char *str);
int	ft_strlen(char *str);
int	ft_strncomp(char *str, char *comp, int n);

#endif
