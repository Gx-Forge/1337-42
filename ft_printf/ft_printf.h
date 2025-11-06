
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
void	ft_put_lower_hex(unsigned int nb, int *count);
void	ft_put_upper_hex(unsigned int nb, int *count);
void	ft_put_u_nbr(unsigned int nb, int *count);
void	ft_put_adress(void *p, int *count);
void	ft_putnbr(int n, int *count);

#endif
