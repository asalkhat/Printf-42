NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putnbru.c ft_putptr.c ft_putstr.c

OBJ := $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $@ $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : clean fclean all re
