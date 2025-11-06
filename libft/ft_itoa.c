
#include "libft.h"

static int	ft_nbrlen(long int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		++len;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			i;
	int			len;
	long int	nb;

	nb = n;
	len = ft_nbrlen(nb);
	if (len == 0)
		++len;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		ptr[i++] = '-';
		nb = -nb;
	}
	ptr[len--] = '\0';
	while (len >= i)
	{
		ptr[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ptr);
}
