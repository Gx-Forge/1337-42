
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	l = 0;
	while (little[l] != '\0')
		++l;
	if (l == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && j < l && i + j < len)
				++j;
			if (l == j)
				return ((char *)(&big[i]));
		}
		++i;
	}
	return (NULL);
}
