
#include <stdlib.h>

int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_nbrlen(long int nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa(int len, long int n, char *base)
{
	int		str_len;
	char	*res;

	len = ft_strlen(base);
	str_len = ft_nbrlen(n, len);
	res = malloc(str_len + 1);
	if (res == NULL)
		return (NULL);
	res[str_len] = '\0';
	if (n == 0)
	{
		res[0] = base[0];
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		res[--str_len] = base[n % len];
		n /= len;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	number;

	if (check_base(base_from) || check_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	return (ft_itoa(0, number, base_to));
}
