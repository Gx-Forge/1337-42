
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_l;
	unsigned int	s_l;

	i = 0;
	d_l = 0;
	s_l = 0;
	while (dest[d_l] != '\0')
		d_l++;
	while (src[s_l] != '\0')
		s_l++;
	if (size <= d_l)
		return (size + s_l);
	while (src[i] != '\0' && (i + d_l < size - 1))
	{
		dest[d_l + i] = src[i];
		i++;
	}
	dest[d_l + i] = '\0';
	return (d_l + s_l);
}
