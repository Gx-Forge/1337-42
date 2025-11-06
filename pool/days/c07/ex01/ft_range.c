
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	i = 0;
	len = 0;
	if (min >= max)
		return (NULL);
	len = max - min;
	arr = malloc(sizeof(int) * len);
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		arr[i] = min;
		++min;
		++i;
	}	
	return (arr);
}
