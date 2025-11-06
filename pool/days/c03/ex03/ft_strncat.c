
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	l;
	unsigned int	i;

	l = 0;
	while (dest[l] != '\0')
		++l;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[l + i] = src[i];
		++i;
	}
	dest[l + i] = '\0';
	return (dest);
}
