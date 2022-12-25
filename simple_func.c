#include "pushswap.h"

void	ft_put_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	terminated(char const *s)
{
	ft_put_fd(s, 2);
	exit(1);
}

int	my_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}
