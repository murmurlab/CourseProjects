CC =					clang

libs	=					libs
libr	=					# -L../murmurlibc -lmurmurc
parrent_dir	=				.
incl	=					$(parrent_dir)/incs
tests	=					$(parrent_dir)/testing
incs	=					-I $(incl) -I $(tests)/incs

wflags	=				-Wall -Wextra -Werror
sanitize =				#-fsanitize=thread #-fsanitize=address
CFLAGS =				-g $(incs) $(wflags) $(sanitize) -pthread

os =					${shell uname -s}

ifeq '$(os)' 'Darwin'
# 	mlxLinkFlags =		-framework OpenGL -framework AppKit -L$(libs)/minilibx_opengl_20191021 -lmlx
# 	incs +=				-I $(libs)/minilibx_opengl_20191021
else ifeq '$(os)' 'Linux'
# 	mlxLinkFlags =		-L minilibx-linux -L$(libs)/minilibx-linux -lmlx -lXext -lX11
# 	incs +=				-I $(libs)/minilibx-linux
endif

src_dir = $(parrent_dir)/srcs
b_src_dir = $(parrent_dir)/srcs

S_SRC =					# $(src_dir)/shared.c \
						# $(tests)/testing.c

B_SRC =					$(b_src_dir)/checker.c \
						$(S_SRC)

SRC =					$(src_dir)/program.c \
						$(src_dir)/utils.c \
						$(src_dir)/utils2.c \
						$(src_dir)/utils3.c \
						$(src_dir)/utils4.c \
						$(src_dir)/utils5.c \
						$(S_SRC)

OBJ =					$(SRC:.c=.o)
B_OBJ =					$(B_SRC:.c=.o)
NAME =					philo
BNAME =					checker
MAKEFLAGS +=			-j$(NPROCS)
# murmurc				=	../murmurlibc/libmurmurc.a
depend				=	# r_murmurc
# $(src_dir)%.o: $(src_dir)%.c
# 	gcc -c $< -o $@ > /dev/null

all:	$(depend) #bonus
	$(MAKE) $(NAME)
	@echo "===================================program======================================\n"

b: bonus

m: mandatory

mandatory: all

bonus:		$(depend) $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(BNAME) $(libr)

$(NAME):	$(murmurc) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(libr)

# mlx:
# ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 -j$(NPROCS) &> /dev/null
# else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux -j$(NPROCS) &> /dev/null
# endif

run: all
	./$(NAME)

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean:					clean
ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 clean
else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux clean
endif
	rm -f $(NAME) $(BNAME) & wait

re:						fclean
	$(MAKE) all
	# $(MAKE) bonus

.PHONY:					re fclean clean all murmurc
