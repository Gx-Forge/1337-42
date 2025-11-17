
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t nb, size_t size);
int		ft_strlen(char *str);
int		ft_strchr(char *str);
char	*get_next_line(int fd);
char	*ft_strtrim(char *store);
char	*ft_strjoin(char *s1, char *s2);

#endif
