
#include "ft_printf.h"

static	int	ft_char_low_ads(unsigned int i)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	return (write(1, &hexa[i], 1));
}

static void	ft_put_lower_adress(unsigned long long int nb, int *count)
{
	if (nb < 16)
		*count += ft_char_low_ads(nb);
	else
	{
		ft_put_lower_adress(nb / 16, count);
		ft_put_lower_adress(nb % 16, count);
	}
}

void	ft_put_adress(void *p, int *count)
{
	unsigned long long int	nb;

	nb = (unsigned long long int)p;
	if (p == NULL)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	*count += write(1, "0x", 2);
	ft_put_lower_adress(nb, count);
}
