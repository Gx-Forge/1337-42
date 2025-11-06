
#include <stdlib.h>

int	check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && check(str[i], charset) == 1)
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && check(src[i], charset) == 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (check(str[i], charset) == 1)
		{
			j++;
			while (str[i] != '\0' && check(str[i], charset) == 1)
				i++;
			if (str[i] == '\0')
				return (j);
		}
		i++;
	}
	return (j);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**arr;

	arr = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (j < count_words(str, charset) && check(str[i], charset) == 1)
		{
			arr[j] = malloc(ft_strlen(&str[i], charset) + 1);
			if (arr[j] == NULL)
				return (NULL);
			ft_strcpy(arr[j], &str[i], charset);
			i += ft_strlen(&str[i], charset);
			j++;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
