
#include "libft.h"

static size_t	ft_strlen_v1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = ft_strlen_v1(s);
	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = s[i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
