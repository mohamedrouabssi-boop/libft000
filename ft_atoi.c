
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	c;
	int		i;
	int		p;

	p = 1;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			p = -1;
		i++;
	}
	c = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		c = c * 10 + (nptr[i] - '0');
		i++;
	}
	return (c * p);
}
