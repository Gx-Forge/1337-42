
#include "ft_printf.h"

static int	ft_char_up_hex(unsigned int i)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	return (write(1, &hexa[i], 1));
}

void	ft_put_upper_hex(unsigned int nb, int *count)
{
	if (nb < 16)
		*count += ft_char_up_hex(nb);
	else
	{
		ft_put_upper_hex(nb / 16, count);
		ft_put_upper_hex(nb % 16, count);
	}
}
