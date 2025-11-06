
char	*ft_strcat(char *dest, char *src)
{
	int	l;
	int	i;

	l = 0;
	while (dest[l] != '\0')
		++l;
	i = 0;
	while (src[i] != '\0')
	{
		dest[l + i] = src[i];
		++i;
	}
	dest[l + i] = '\0';
	return (dest);
}