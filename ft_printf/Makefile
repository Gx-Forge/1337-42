
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c  ft_put_adress.c  ft_put_lower_hex.c  ft_putstr.c	  ft_put_upper_hex.c \
		  ft_putchar.c     ft_putnbr.c	  ft_put_u_nbr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean