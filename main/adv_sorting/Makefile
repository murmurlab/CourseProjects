CC =					clang

tests	=					testing
libs	=					libs
libr	=					-L../murmurlibc -lmurmurc
incl	=					incs
incs	=					-I $(incl) -I ../murmurlibc -I $(tests)/incs

wflags	=				-Wall -Wextra -Werror
CFLAGS =				-D BUFFER_SIZE=65535 -std=c99 -g $(incs)

os =					${shell uname -s}

ifeq '$(os)' 'Darwin'
# 	mlxLinkFlags =		-framework OpenGL -framework AppKit -L$(libs)/minilibx_opengl_20191021 -lmlx
# 	incs +=				-I $(libs)/minilibx_opengl_20191021
else ifeq '$(os)' 'Linux'
# 	mlxLinkFlags =		-L minilibx-linux -L$(libs)/minilibx-linux -lmlx -lXext -lX11
# 	incs +=				-I $(libs)/minilibx-linux
endif

src_dir = srcs
b_src_dir = srcs

S_SRC =					$(src_dir)/shared.c \
						$(tests)/testing.c

B_SRC =					$(b_src_dir)/checker.c \
						$(S_SRC)

SRC =					$(src_dir)/program.c \
						$(src_dir)/program_utils.c \
						$(src_dir)/program_utils2.c \
						$(S_SRC)

OBJ =					$(SRC:.c=.o)
B_OBJ =					$(B_SRC:.c=.o)
NAME =					push_swap
BNAME =					checker
MAKEFLAGS +=			-j$(NPROCS)

# $(src_dir)%.o: $(src_dir)%.c
# 	gcc -c $< -o $@ > /dev/null

all:		$(NAME) #bonus
	@echo "===================================program======================================\n"

b: bonus

bonus:		depend $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(BNAME) $(libr)

$(NAME):	depend $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(libr)

depend:		libmurmurc

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
	rm -f $(OBJ) $(B_OBJ)

fclean:					clean
ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 clean
else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux clean
endif
	make -C ../murmurlibc clean &
	rm -f $(NAME) $(BNAME) & wait

re:						fclean
	$(MAKE) all
	$(MAKE) bonus

.PHONY:					re fclean clean libmurmurc depend all 
