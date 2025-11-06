
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = 0;
	len_s = 0;
	i = 0;
	while (dst[len_d] != '\0')
		++len_d;
	while (src[len_s] != '\0')
		++len_s;
	if (len_d >= size)
		return (len_s + size);
	while (len_d + i < size - 1 && src[i] != '\0')
	{
		dst[len_d + i] = src[i];
		++i;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}
