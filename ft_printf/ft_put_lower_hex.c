
#include "ft_printf.h"

static	int	ft_char_low_hex(unsigned int i)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	return (write(1, &hexa[i], 1));
}

void	ft_put_lower_hex(unsigned int nb, int *count)
{
	if (nb < 16)
		*count += ft_char_low_hex(nb);
	else
	{
		ft_put_lower_hex(nb / 16, count);
		ft_put_lower_hex(nb % 16, count);
	}
}
