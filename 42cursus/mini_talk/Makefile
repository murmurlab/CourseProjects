CC		= cc
CFLAGS	= -Wall -Wextra -Werror
libft	= ../libft/libft

libft:
	cd ../libft
	make re
all: libft
	${CC} client.c libft -o client
	${CC} server.c libft -o server
clean:
	rm -fr client server
re: clean all