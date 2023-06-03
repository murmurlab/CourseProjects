CC = 			cc
CFLAGS = 		-std=c99 -g #-Wall -Werror -Werror
mlxLinkFlags = 	-lmlx -lXext -lX11 -L minilibx-linux

src = ${shell find . -maxdepth 1 -name '*.c'}
NAME = ${src:.c=.o}
program = game

all: $(NAME) mlx murmurlibc
	$(CC) $(CFLAGS) -o $(program) $(NAME) minilibx-linux/libmlx_Linux.a ../murmurlibc/murmurlibc.a $(mlxLinkFlags)
$(NAME):

murmurlibc:
	make -C ../murmurlibc
mlx:
	make -C minilibx-linux

clean:
	make -C ../murmurlibc
	find . -maxdepth 1 -name "*.o" -exec rm {} +
fclean: clean
	rm -f $(program)
re: fclean all

.PHONY: re fclean clean mlx murmurlibc all