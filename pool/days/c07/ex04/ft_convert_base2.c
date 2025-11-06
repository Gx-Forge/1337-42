
int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	type_and_start(char *str, int *start)
{
	int	i;
	int	type;

	i = 0;
	type = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			type *= -1;
		else if (str[i] == '+')
			type *= 1;
		else
			break ;
		i++;
	}
	*start = i;
	return (type);
}

int	ft_end(char *str, char *base, int start)
{
	int	j;
	int	end;

	j = 0;
	end = 0;
	while (str[start] != '\0')
	{
		j = 0;
		while (str[start] != base[j] && base[j] != '\0')
			j++;
		if (base[j] == '\0')
		{
			end = start;
			break ;
		}
		start++;
	}
	if (str[start] == '\0')
		end = start;
	return (end);
}

int	base_to_decimal(char *str, char *base, int start, int end)
{
	int	len_b;
	int	number;
	int	index;

	len_b = 0;
	number = 0;
	while (base[len_b] != '\0')
		len_b++;
	while (start < end)
	{
		index = 0;
		while (str[start] != base[index])
			index++;
		number = (number * len_b) + index;
		start++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int			number;
	int			type;
	int			check;
	int			start;
	int			end;

	check = check_base(base);
	if (check == 1)
		return (0);
	type = type_and_start(str, &start);
	end = ft_end(str, base, start);
	number = base_to_decimal(str, base, start, end) * type;
	return (number);
}
