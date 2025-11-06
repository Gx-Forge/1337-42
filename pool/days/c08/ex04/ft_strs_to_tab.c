
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*arr;

	i = ft_strlen(src);
	arr = malloc(i + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		arr[i] = src[i];
		++i;
	}
	arr[i] = '\0';
	return (arr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;

	i = 0;
	arr = malloc (sizeof(t_stock_str) * (ac + 1));
	if (arr == NULL)
		return (0);
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		if (arr[i].copy == NULL)
		{
			while (i > 0)
			{
				free(arr[i--].copy);
			}
			free (arr);
			return (NULL);
		}
		++i;
	}
	arr[i].str = NULL;
	return (arr);
}
