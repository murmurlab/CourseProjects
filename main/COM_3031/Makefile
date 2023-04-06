CC		= cc
DBG		=
CFLAGS	= $(DBG) -Wall -Wextra -Werror
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)
murmurlib	= ../murmurlibc/murmurlib.a

all:		murmurlib $(OBJ)
	${CC} ${CFLAGS} client.o ../murmurlibc/murmurlib.a -o client
	${CC} ${CFLAGS} server.o ../murmurlibc/murmurlib.a -o server
bonus:

murmurlib:
	make -C ../murmurlibc re
clean:
	rm -fr $(OBJ)
fclean:		clean
	rm -fr client server
re:			fclean all

.PHONY: libft libftprintf all clean fclean re