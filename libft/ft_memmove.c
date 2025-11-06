
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*str;
	unsigned char		*dst;
	size_t				i;

	str = (const unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	if (dst > str && dst < str + n)
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = str[i - 1];
			--i;
		}
	}
	else
	{
		while (i < n)
		{
			dst[i] = str[i];
			++i;
		}
	}
	return (dest);
}
