#include "library.h"
void	ft_error(char *str)
{
	red();
	ft_putstr(str);
	exit(1);
}
