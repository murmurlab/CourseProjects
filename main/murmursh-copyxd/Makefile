wflags	=				# -Wall -Wextra -Werror
os =					${shell uname -s}

ifeq '$(os)' 'Darwin'
	ltinfo =
	wflags += -std=c99
# 	mlxLinkFlags =		-framework OpenGL -framework AppKit -L$(libs)/minilibx_opengl_20191021 -lmlx
# 	incs +=				-I $(libs)/minilibx_opengl_20191021
else ifeq '$(os)' 'Linux'
	ltinfo =			-ltinfo
# 	mlxLinkFlags =		-L minilibx-linux -L$(libs)/minilibx-linux -lmlx -lXext -lX11
# 	incs +=				-I $(libs)/minilibx-linux
endif

CC =						gcc

# rl		=					-L /goinfre/$(shell whoami)/homebrew/Cellar/readline/8.2.7/lib -lreadline
# rlI		=					-I /goinfre/$(shell whoami)/homebrew/Cellar/readline/8.2.7/include
rl		=					-L lib/lib/readline/lib -lreadline $(ltinfo)
rlI		=					-I lib/lib/readline/include

sanitize =					-fsanitize=address #-fsanitize=thread
libs	=					libs
libr	=					$(rl) -L./libultift -lft
parrent_dir	=				sh
incl	=					$(parrent_dir)/incs
tests	=					$(parrent_dir)/testing
incs	=					-I $(incl) -I ./libultift -I $(tests)/incs $(rlI)
							

test:=					0
vars :=					-D BUFFER_SIZE=65535 \
						-D TEST=$(test)
CFLAGS :=				$(vars) -g $(incs) $(wflags)

src_dir = $(parrent_dir)/srcs
b_src_dir = $(parrent_dir)/srcs

S_SRC =					$(tests)/testing.c

B_SRC =					$(b_src_dir)/checker.c \
						$(S_SRC)

SRC =					$(src_dir)/program.c \
						$(src_dir)/utils.c \
						$(src_dir)/test.c \
						$(S_SRC)

OBJ =					$(SRC:.c=.o)
B_OBJ =					$(B_SRC:.c=.o)
NAME =					minishell
BNAME =					checker
MAKEFLAGS +=			-j$(NPROCS)
murmurc				=	./libultift/libft.a
lrl				=	./lib/lib/readline/lib/libreadline.a
depend				=	r_murmurc r_rl
# $(src_dir)%.o: $(src_dir)%.c
# 	gcc -c $< -o $@ > /dev/null

all:	$(depend) #bonus
	$(MAKE) $(NAME)
	@echo "===================================program======================================\n"

# t:
# 	$(MAKE) clean
# 	$(MAKE) all

b: bonus

m: mandatory

mandatory: all

bonus:		$(depend) $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(BNAME) $(libr)

$(NAME):	$(murmurc) $(lrl) $(OBJ)
	$(CC) $(CFLAGS) $(sanitize) $(OBJ) $(libr) -o $(NAME)

r_murmurc:
	make -C ./libultift -j$(NPROCS)

r_rl:
	# make -C ./lib -j$(NPROCS)

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

fclean:		clean
ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 clean
else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux clean
endif
	# make -C ./libultift clean &
	# make -C ./lib fclean &
	rm -f $(NAME) $(BNAME) & wait

re:						fclean
	$(MAKE) all
	# $(MAKE) bonus

.PHONY:					re fclean clean all murmurc