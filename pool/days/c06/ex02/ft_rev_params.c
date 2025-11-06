
#include <unistd.h>

int	main(int ac, char **av)
{
	int	j;

	while (ac > 1)
	{
		j = 0;
		while (av[ac - 1][j] != '\0')
		{
			write(1, &av[ac - 1][j], 1);
			++j;
		}
		write(1, "\n", 1);
		--ac;
	}
	return (0);
}
