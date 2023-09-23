CC =					cc

libs =					libs
libr =					-L../murmurlibc -lmurmurc
incs =					-I incs -I ../murmurlibc

CFLAGS =				-D BUFFER_SIZE=65535 -std=c99 -g -Wall -Wextra -Werror $(incs)

os =					${shell uname -s}

ifeq '$(os)' 'Darwin'
# 	mlxLinkFlags =		-framework OpenGL -framework AppKit -L$(libs)/minilibx_opengl_20191021 -lmlx
# 	incs +=				-I $(libs)/minilibx_opengl_20191021
else ifeq '$(os)' 'Linux'
# 	mlxLinkFlags =		-L minilibx-linux -L$(libs)/minilibx-linux -lmlx -lXext -lX11
# 	incs +=				-I $(libs)/minilibx-linux
endif

src_dir = srcs
b_src_dir = b_srcs

B_SRC =					# $(b_src_dir)/

SRC =					$(src_dir)/program.c \
						$(src_dir)/testing.c

OBJ =					${SRC:.c=.o}
B_OBJ =					${B_SRC:.c=.o}
NAME =					push_swap
bonus =					ceker
MAKEFLAGS +=			-j$(NPROCS)

# $(src_dir)%.o: $(src_dir)%.c
# 	gcc -c $< -o $@ > /dev/null

all:					$(NAME) #bonus
	@echo "===================================program======================================\n"
bonus:					depend $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(bonus) $(libr)

$(NAME):				depend $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(libr)

depend:					libmurmurc

libmurmurc:
	make -C ../murmurlibc -j$(NPROCS)

# mlx:
# ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 -j$(NPROCS) &> /dev/null
# else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux -j$(NPROCS) &> /dev/null
# endif

run: all
	./push_swap

clean:
	rm -f $(OBJ)
# 	rm -f $(B_OBJ)

fclean:					clean
ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 clean
else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux clean
endif
	make -C ../murmurlibc clean &
	rm -f $(program) & wait

re:						fclean
	$(MAKE) all

.PHONY:					re fclean clean libmurmurc depend all 
