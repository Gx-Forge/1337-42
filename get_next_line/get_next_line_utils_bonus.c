
#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

void	*ft_calloc(size_t nb, size_t size)
{
	char	*p;
	size_t	i;

	if (nb == 0 || size == 0)
		return (malloc(1));
	p = malloc(size * nb);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size * nb)
	{
		p[i] = 0;
		++i;
	}
	return (p);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char *store)
{
	int		i;
	int		len;
	char	*str;

	if (!store)
		return (NULL);
	i = 0;
	len = ft_strlen(store);
	while (store[i] != '\n' && store[i] != '\0')
		++i;
	if (store[i] == '\0')
	{
		free(store);
		return (NULL);
	}
	++i;
	str = ft_calloc((len - i) + 1, 1);
	if (!str)
		return (free(store), NULL);
	len = 0;
	while (store[i] != '\0')
		str[len++] = store[i++];
	free(store);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	flen;
	size_t	i;
	size_t	j;
	char	*ptr;

	flen = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	ptr = malloc(flen + 1);
	if (!ptr)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
