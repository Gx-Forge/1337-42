
#include "libft.h"

static size_t	ft_strlen_v2(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	flen;
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	flen = ft_strlen_v2(s1) + ft_strlen_v2(s2);
	i = 0;
	ptr = malloc(flen + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
