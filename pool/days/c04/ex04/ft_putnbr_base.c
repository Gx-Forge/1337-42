
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
		++len;
	return (len);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

void	ft_putnbr(long int nbr, int len, char *base)
{
	if (nbr < len)
		ft_putchar(base[nbr]);
	else
	{
		ft_putnbr(nbr / len, len, base);
		ft_putnbr(nbr % len, len, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			check;
	int			len;
	long int	nb;

	if (base == NULL)
		return ;
	check = check_base(base);
	if (check == 1)
		return ;
	len = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < len)
		ft_putchar(base[nb]);
	else
		ft_putnbr(nb, len, base);
}
