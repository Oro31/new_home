#include "minishell.h"

static int ft_init(char *c)
{
	if (*c == '0')
		return (write(1, "0\n", 2));
	*c = 'B';
	return (0);
}

static int ft_lecture(char *c)
{
	if (*c == 'B')
		return (write(1, "B\n", 2));
	*c = 'C';
	return (0);
}

static int ft_destruct(char *c)
{
	if (*c == 'B')
		return (write(1, "C\n", 2));
	*c = 'E';
	return (0);

} 

int	main(void)
{
	char c = 'B';
	if (
			!ft_lecture(&c)
			|| !ft_init(&c)
			|| ft_destruct(&c)
		)
		return (write(1, &c, 1));
	printf("SORTIE %c\n", c);
	return(0);
}
