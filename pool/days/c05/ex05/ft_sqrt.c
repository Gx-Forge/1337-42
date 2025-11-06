
int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		else if (i * i > nb)
			return (0);
		i++;
	}
	return (0);
}
