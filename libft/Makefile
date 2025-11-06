
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

FILES_C = ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
	  ft_bzero.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
	  ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
	  ft_isalnum.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalpha.c \
	  ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isascii.c ft_memmove.c \
	  ft_strdup.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_striteri.c \
	  ft_strrchr.c ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c

BONUS_C = ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c \
			ft_lstadd_front_bonus.c ft_lstiter_bonus.c ft_lstnew_bonus.c \
			ft_lstclear_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c

FILES_O = $(FILES_C:.c=.o)
BONUS_O = $(BONUS_C:.c=.o)

all: $(NAME)

$(NAME): $(FILES_O)
	ar rcs $(NAME) $(FILES_O)

bonus:  $(BONUS_O)
	ar rcs $(NAME) $(BONUS_O)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(FILES_O) $(BONUS_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
