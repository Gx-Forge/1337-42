
#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		*count += ft_putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
		*count += ft_putchar(nb + '0');
	else
	{
		ft_putnbr((nb / 10), count);
		ft_putnbr((nb % 10), count);
	}
}
