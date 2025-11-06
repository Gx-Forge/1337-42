
#include "libft.h"

static size_t	ft_strlen_v3(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen_v3(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		--i;
	}
	return (NULL);
}
