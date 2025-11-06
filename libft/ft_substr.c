
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen_v4(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (ft_strlen_v4(s) <= start)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	i = start;
	j = 0;
	while (s[i++] != '\0' && j < len)
		++j;
	ptr = malloc(j + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
