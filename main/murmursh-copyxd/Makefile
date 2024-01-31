wflags	=				-Wall -Wextra -Werror
os =					${shell uname -s}

ifeq '$(os)' 'Darwin'
	ltinfo =
	wflags += -std=c99
else ifeq '$(os)' 'Linux'
	ltinfo =			-ltinfo
endif

CC =						gcc

# rl		=					-L /goinfre/$(shell whoami)/homebrew/Cellar/readline/8.2.7/lib -lreadline
# rlI		=					-I /goinfre/$(shell whoami)/homebrew/Cellar/readline/8.2.7/include
rl		=					-L lib/lib/readline/lib -lreadline $(ltinfo)
rlI		=					-I lib/lib/readline/include

sanitize =					#-fsanitize=address #-fsanitize=thread
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

B_SRC =					$(S_SRC)


SRC =					$(src_dir)/program.c \
						$(src_dir)/builtins0.c \
						$(src_dir)/builtins1.c \
						$(src_dir)/check0.c \
						$(src_dir)/check1.c \
						$(src_dir)/environment0.c \
						$(src_dir)/environment1.c \
						$(src_dir)/executer0.c \
						$(src_dir)/executer1.c \
						$(src_dir)/executer2.c \
						$(src_dir)/expander0.c \
						$(src_dir)/expander1.c \
						$(src_dir)/expander2.c \
						$(src_dir)/initialization0.c \
						$(src_dir)/parser0.c \
						$(src_dir)/parser1.c \
						$(src_dir)/utils0.c \
						$(src_dir)/utils1.c \
						$(src_dir)/utils2.c \
						$(src_dir)/utils3.c \
						$(src_dir)/preparatory0.c \
						$(src_dir)/preparatory1.c \
						$(src_dir)/preparatory2.c \
						$(src_dir)/syntax0.c \
						$(src_dir)/syntax1.c \
						$(src_dir)/test.c \
						$(S_SRC)

OBJ =					$(SRC:.c=.o)
B_OBJ =					$(B_SRC:.c=.o)
NAME =					minishell
BNAME =					
MAKEFLAGS +=			-j$(NPROCS)
murmurc				=	./libultift/libft.a
lrl				=	./lib/lib/readline/lib/libreadline.a
depend				=	r_murmurc
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
	make -C ./libultift all -j$(NPROCS)

$(lrl):
	$(MAKE) -C lib -j$(NPROCS) DIR=$(PWD)/lib

run: all
	./$(NAME)

clean:
	rm -f $(OBJ) $(B_OBJ)
	make -C ./libultift clean

fclean:		clean
ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 clean
else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux clean
endif
	make -C ./libultift fclean & make -C ./lib fclean & rm -f $(NAME) $(BNAME) & wait

re:						fclean
	$(MAKE) all
	# $(MAKE) bonus

.PHONY:					re fclean clean all