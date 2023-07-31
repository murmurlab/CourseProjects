CC = 					clang
CFLAGS = 				-D BUFFER_SIZE=1000000 -std=c99 -g #-Wall -Werror -Werror
mlxLinkFlags_linux = 	-lmlx -lXext -lX11 -L minilibx-linux
mlxLinkFlagsOSX =		-framework OpenGL -framework AppKit
os = ${shell uname -s}
src = ${shell find . -maxdepth 1 -name '*.c'}
NAME = ${src:.c=.o}
program = game

all: $(NAME) mlx murmurlibc
ifeq '$(os)' 'Darwin'
	pwd | cat
	$(CC) $(CFLAGS) -o $(program) $(NAME) minilibx_opengl_20191021/libmlx.a ../murmurlibc/murmurlibc.a $(mlxLinkFlagsOSX)
else ifeq '$(os)' 'Linux'
	pwd | cat
	$(CC) $(CFLAGS) -o $(program) $(NAME) minilibx-linux/libmlx_Linux.a ../murmurlibc/murmurlibc.a $(mlxLinkFlags_linux)
endif
$(NAME):

murmurlibc:
	make -C ../murmurlibc
mlx:
ifeq "$(os)" "Darwin"
	make -C minilibx_opengl_20191021
else ifeq ($(os),Linux)
	make -C minilibx-linux
endif
clean:
	find . -maxdepth 1 -name "*.o" -exec rm {} +
fclean: clean
ifeq "$(os)" "Darwin"
	make -C minilibx_opengl_20191021 clean
else ifeq ($(os),Linux)
	make -C minilibx-linux clean
endif
	make -C ../murmurlibc clean
	rm -f $(program)
re: fclean all

.PHONY: re fclean clean mlx murmurlibc all