
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	p = malloc(size * nmemb);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		p[i] = 0;
		++i;
	}
	return (p);
}
