
int	ft_atoi(char *str)
{
	int	number;
	int	i;
	int	type;

	number = 0;
	i = 0;
	type = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			type *= -1;
		else if (!(str[i] == '-' || str[i] == '+' ))
			break ;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		++i;
	}
	return (number * type);
}
