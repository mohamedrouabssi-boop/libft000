
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		dst = malloc(1);
		((unsigned char *)dst)[0] = 0;
		return ((void *)(dst));
	}
	if (size > (size_t) - 1 / nmemb)
		return (NULL);
	dst = malloc(nmemb * size);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)dst)[i] = 0;
		i++;
	}
	return (((void *)dst));
}
