
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		*p;
	size_t				i;

	ptr = (const unsigned char *)src;
	p = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		p[i] = ptr[i];
		++i;
	}
	return (dest);
}
