CC		= cc
DBG		= ""
CFLAGS	= $(DBG) -Wall -Wextra -Werror
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)
libft	= ../libft/libft

all:		libftprintf libft $(OBJ)
	${CC} ${CFLAGS} client.o ../libft/libft.a ../ft_printf/spagetti/libftprintf.a -o client
	${CC} ${CFLAGS} server.o ../libft/libft.a ../ft_printf/spagetti/libftprintf.a -o server
libft:
	make -C ../libft re
libftprintf:
	make -C ../ft_printf/spagetti re
clean:
	rm -fr $(OBJ)
fclean:		clean
	rm -fr client server
re:			fclean all

.PHONY: libft libftprintf all clean fclean re