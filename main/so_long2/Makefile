CC =					cc

libs =					libs
libr =					-L../murmurlibc -lmurmurc
incs =					-I incs -I ../murmurlibc

CFLAGS =				-D BUFFER_SIZE=65535 -std=c99 -g -Wall -Wextra -Werror $(incs)

os =					${shell uname -s}

ifeq '$(os)' 'Darwin'
	mlxLinkFlags =		-framework OpenGL -framework AppKit -L$(libs)/minilibx_opengl_20191021 -lmlx
	incs +=				-I $(libs)/minilibx_opengl_20191021
else ifeq '$(os)' 'Linux'
	mlxLinkFlags =		-L minilibx-linux -L$(libs)/minilibx-linux -lmlx -lXext -lX11
	incs +=				-I $(libs)/minilibx-linux
endif

src_dir = srcs
b_src_dir = b_srcs

B_SRC =					$(b_src_dir)/

SRC =					$(src_dir)/game.c			\
						$(src_dir)/game_utils.c	\
						$(src_dir)/game_utils2.c	\
						$(src_dir)/game_utils3.c	\
						$(src_dir)/game_utils4.c	\
						$(src_dir)/game_utils5.c	\
						$(src_dir)/game_utils6.c	\
						$(src_dir)/game_utils7.c

OBJ =					${SRC:.c=.o}
B_OBJ =					${B_SRC:.c=.o}
NAME =					game
bonus =					game_bonus
MAKEFLAGS +=			-j$(NPROCS)

all:					$(NAME) #bonus

bonus:				depend $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(bonus) $(mlxLinkFlags) $(libr)

$(NAME):				depend $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(mlxLinkFlags) $(libr)

depend:					libmurmurc mlx

libmurmurc:
	make -C ../murmurlibc -j$(NPROCS)

mlx:
ifeq "$(os)" "Darwin"
	make -C $(libs)/minilibx_opengl_20191021 -j$(NPROCS) &> /dev/null
else ifeq ($(os),Linux)
	make -C $(libs)/minilibx-linux -j$(NPROCS) &> /dev/null
endif

clean:
	rm -f $(OBJ)
# 	rm -f $(B_OBJ)

fclean:					clean
ifeq "$(os)" "Darwin"
	make -C $(libs)/minilibx_opengl_20191021 clean
else ifeq ($(os),Linux)
	make -C $(libs)/minilibx-linux clean
endif
	make -C ../murmurlibc clean &
	rm -f $(program) & wait

re:						fclean
	$(MAKE) all

.PHONY:					re fclean clean mlx libmurmurc depend all 
