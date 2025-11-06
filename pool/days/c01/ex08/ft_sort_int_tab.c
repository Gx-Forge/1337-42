
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = size - 1;
	while (i <= j)
	{
		k = 0;
		while (k < j)
		{
			if (tab[k] > tab[k + 1])
				ft_swap(&tab[k], &tab[k + 1]);
			k++;
		}
		i++;
	}
}
