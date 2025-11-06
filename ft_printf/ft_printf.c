
#include "ft_printf.h"

int	ft_call_function(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), &len);
	else if (c == 'p')
		ft_put_adress(va_arg(args, void *), &len);
	else if (c == 'x')
		ft_put_lower_hex(va_arg(args, unsigned int), &len);
	else if (c == 'X')
		ft_put_upper_hex(va_arg(args, unsigned int), &len);
	else if (c == 'u')
		ft_put_u_nbr(va_arg(args, unsigned int), &len);
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == '\0')
		return (-1);
	else
		len += (ft_putchar('%') + ft_putchar(c));
	return (len);
}

int	ft_hp(const char *str, int *i, va_list args)
{
	int	buffer;

	buffer = 0;
	++(*i);
	while (str[*i] == ' ' && str[*i] != '\0')
		++(*i);
	buffer += ft_call_function(str[*i], args);
	if (buffer == -1)
		return (-1);
	++(*i);
	return (buffer);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		buffer;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			buffer = 0;
			buffer += ft_hp(str, &i, args);
			if (buffer == -1)
				return (-1);
			len += buffer;
		}
		else
			len += ft_putchar(str[i++]);
	}
	va_end(args);
	return (len);
}
