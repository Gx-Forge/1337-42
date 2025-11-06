
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*arr;

	i = 0;
	while (src[i] != '\0')
		++i;
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
