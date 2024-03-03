wflags	=				-Wall -Wextra -Werror -std=c++98
os =					${shell uname -s}

ifeq '$(os)' 'Darwin'

else ifeq '$(os)' 'Linux'

endif

CC =						clang++

sanitize =					-fsanitize=address #-fsanitize=thread
libs	=					libs
libr	=					# -L./libultift -lft
parrent_dir	=				.
incl	=					$(parrent_dir)/incs
tests	=					$(parrent_dir)/testing
incs	=					-I $(incl) -I ./libultift -I $(tests)/incs
							

test:=					0
vars :=					-D BUFFER_SIZE=65535 \
						-D TEST=$(test)
CFLAGS :=				$(vars) -g $(incs) $(wflags)

src_dir = $(parrent_dir)/
b_src_dir = $(parrent_dir)/srcs

S_SRC =					$(tests)/testing.c

B_SRC =					$(b_src_dir)/checker.c \
						$(S_SRC)

SRC =					$(src_dir)/megaphone.cpp \
						# $(S_SRC)

OBJ =					$(SRC:.c=.o)
B_OBJ =					$(B_SRC:.c=.o)
NAME =					megaphone
BNAME =					checker
MAKEFLAGS +=			-j$(NPROCS)
murmurc =				./libultift/libft.a
depend =				#r_murmurc r_rl
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

$(NAME):	$(depend) $(OBJ)
	$(CC) $(CFLAGS) $(sanitize) $(OBJ) $(libr) -o $(NAME)

# r_murmurc:
# 	make -C ./libultift -j$(NPROCS)

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

.PHONY:					re fclean clean all