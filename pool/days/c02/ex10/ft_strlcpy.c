
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = 0;
	while (src[l] != '\0')
		l++;
	if (size == 0)
		return (l);
	while (i < size - 1)
	{
		if (src[i] != '\0')
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (l);
}
