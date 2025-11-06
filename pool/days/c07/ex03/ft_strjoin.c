
#include <stdlib.h>

int	ft_total_len(int *sep_len, int size, char **strs, char *sep)
{
	int	len;
	int	j;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		len += j;
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	*sep_len = i * (size - 1);
	return (len);
}

char	*ft_retstr(char *sep, char **strs, int *len, int size)
{
	int		j;
	int		i;
	char	*arr;

	arr = malloc(*len + 1);
	if (arr == NULL)
		return (NULL);
	*len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			arr[(*len)++] = strs[i][j++];
		}		
		j = 0;
		while (i < size - 1 && sep[j] != '\0')
		{
			arr[(*len)++] = sep[j++];
		}
		i++;
	}
	return (arr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	char	*arr;

	if (size == 0)
	{
		arr = malloc(1);
		arr[0] = '\0';
		return (arr);
	}
	len = ft_total_len(&i, size, strs, sep);
	arr = malloc(len + i + 1);
	if (arr == NULL)
		return (NULL);
	len += i;
	arr = ft_retstr(sep, strs, &len, size);
	arr[len] = '\0';
	return (arr);
}
