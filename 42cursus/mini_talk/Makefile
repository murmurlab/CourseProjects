CC		= cc
DBG		= ""
CFLAGS	= $(DBG) -Wall -Wextra -Werror
libft	= ../libft/libft

all: libftprintf libft
	${CC} ${CFLAGS} client.c ../libft/libft.a ../ft_printf/spagetti/libftprintf.a -o client
	${CC} ${CFLAGS} server.c ../libft/libft.a ../ft_printf/spagetti/libftprintf.a -o server
libft:
	make -C ../libft re
libftprintf:
	make -C ../ft_printf/spagetti re
clean:
	rm -fr client server
re: clean all

.PHONY: libft libftprintf all clean re