
#include "libft.h"

static void	*ft_free(char **ptr, int i, int *range)
{
	--i;
	while (i > 0)
		free(ptr[--i]);
	free(ptr);
	free(range);
	return (NULL);
}

static int	ft_countword_2(char const *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			++words;
			while (str[i] != c && str[i] != '\0')
				++i;
			--i;
		}
		++i;
	}
	return (words);
}

static int	ft_countword(char const *str, char c, int **range)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	j = 0;
	words = ft_countword_2(str, c);
	*range = malloc(sizeof(int) * (words));
	if (!(*range))
		return (0);
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			j = 0;
			while (str[i] != '\0' && str[i++] != c)
				++j;
			(*range)[words++] = j;
			--i;
		}
		++i;
	}
	return (words);
}

static char	*ft_ret_str(char const *s, char c, int *i, int len)
{
	char	*str;
	int		j;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		str[j] = s[*i];
		++(*i);
		++j;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**stringes;
	int		wordes;
	int		*range;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wordes = ft_countword(s, c, &range);
	stringes = malloc(sizeof(char *) * (wordes + 1));
	if (!stringes)
		return (NULL);
	while (i < wordes)
	{
		while (s[j] == c && s[j] != '\0')
			++j;
		stringes[i] = ft_ret_str (s, c, &j, range[i]);
		if (!stringes[i++])
			return (ft_free(stringes, i, range));
	}
	stringes[i] = NULL;
	free(range);
	return (stringes);
}
