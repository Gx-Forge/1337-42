
#include "libft.h"

static int	check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static int	ft_gx_strlen(char const *str, char const *set)
{
	int	len;
	int	start;
	int	end;

	start = 0;
	len = 0;
	while (str[len] != '\0')
		++len;
	end = len - 1;
	while (check(str[start], set) == 1)
		++start;
	if (str[start] == '\0')
		return (0);
	while (check(str[end], set) == 1)
		--end;
	len = end - start;
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	int		j;
	char	*ptr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_gx_strlen(s1, set);
	start = 0;
	j = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (check(s1[start], set) == 1)
		++start;
	while (j < len)
	{
		ptr[j] = s1[start];
		++j;
		++start;
	}
	ptr[j] = '\0';
	return (ptr);
}
