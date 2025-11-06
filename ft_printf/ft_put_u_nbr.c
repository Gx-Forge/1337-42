
#include "ft_printf.h"

void	ft_put_u_nbr(unsigned int nb, int *count)
{
	if (nb <= 9)
		*count += ft_putchar(nb + '0');
	else
	{
		ft_put_u_nbr(nb / 10, count);
		ft_put_u_nbr(nb % 10, count);
	}
}
