/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:57:59 by nel-adao          #+#    #+#             */
/*   Updated: 2025/11/15 07:51:52 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_return_str(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		++i;
	ret = ft_calloc(i + 2, 1);
	if (!ret)
		return (free(str), NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		++i;
	}
	if (str[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*ft_reader(char *store, int fd)
{
	char	*buffer;
	int		ret;

	ret = 1;
	if (store == NULL)
	{
		store = ft_calloc(1, 1);
		if (!store)
			return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (free(store), NULL);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (free(buffer), free(store), NULL);
		buffer[ret] = '\0';
		store = ft_strjoin(store, buffer);
		if (ft_strchr(buffer) == 1)
			break ;
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = ft_reader(store[fd], fd);
	if (store[fd] == NULL)
		return (NULL);
	str = ft_return_str(store[fd]);
	store[fd] = ft_strtrim(store[fd]);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (free(str), free(store[fd]), NULL);
	return (str);
}
