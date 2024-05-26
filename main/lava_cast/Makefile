CC					=	clang
RM					=	rm -rf
DEFINES				=	-D BUFFER_SIZE=65535
CFLAGS				=	-std=c99 $(DEFINES)

DIR					=	$(shell echo $(PWD))
PROGRAM				=	cub3d
LIB_DIR				=	lib
SRC_DIR				=	src
OBJ_DIR				=	.objs
BIN_DIR				=	.bin
NAME				=	$(BIN_DIR)/$(PROGRAM)
# CMD_DIR			=	cmd
# INC_DIR			=	-I $(SRC_DIR)/incs

program_dir			=	$(SRC_DIR)

#lib paths######################################################################
# readline_L		=	-L $(LIB_DIR)/readline/lib/readline/lib -lreadline $(ltinfo)
minilibx-linux_L	=	-L $(LIB_DIR)/minilibx-linux -lmlx
################################################################################

#inc paths######################################################################
# readline_I		=	-I $(LIB_DIR)/readline/lib/readline/include
minilibx-linux_I	=	-I $(LIB_DIR)/minilibx-linux/
lava_caster_I		=	-I $(program_dir)/incs/
# murmur_test_I		=	-I $(LIB_DIR)/murmurtest/incs/
################################################################################

# readline_A			=	$(LIB_DIR)/readline/lib/libreadline.a
minilibx-linux_A	=	$(LIB_DIR)/minilibx-linux/libmlx.a

libr				=	$(minilibx-linux_L)


incs				=	$(lava_caster_I) \
						$(minilibx-linux_I)

CFLAGS				+=	$(incs)

SRCS				=	$(SRC_DIR)/main/events/init.c
OBJS				=	$(SRCS:.c=.o)

CMD					=	$(SRC_DIR)/main/lava_cast.c
CMD_OBJS			=	$(CMD:.c=.o)
# CMD				=	$(PROGRAM).c

DEPENDENCIES		=	$(minilibx-linux_A)


os = ${shell uname -s}
ifeq '$(os)' 'Darwin'
NPROCS = $(shell sysctl -n hw.ncpu)
else ifeq '$(os)' 'Linux'
NPROCS = $(shell nproc)
endif
# MAKEFLAGS += -j$(NPROCS)

w = 1
ifeq '$(w)' '1'
CFLAGS += -Wextra -Werror -Wall
endif

debug = 1
ifeq '$(debug)' '1'
CFLAGS += -g
endif

asan = 1
ifeq '$(asan)' '1'
# CFLAGS += -fsanitize=address
# CFLAGS += -fsanitize=thread
endif

test = 0
ifeq '$(test)' '1'
CFLAGS += -D TEST=$(test)
./$(attest) .
endif

all: $(DEPENDENCIES)
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(NAME)

# b: bonus

m: mandatory

mandatory: all

# $(READLINE):
# 	@curl -O https://ftp.gnu.org/gnu/readline/readline-8.2-rc1.tar.gz
# 	@tar -xvf readline-8.2-rc1.tar.gz
# 	@$(RM) readline-8.2-rc1.tar.gz
# 	@cd readline-8.2-rc1 && ./configure --prefix=$(DIR)/lib/readline && make && make install
# 	@$(RM) readline-8.2-rc1

# $(lrl):
# 	$(MAKE) -C lib -j$(NPROCS) DIR=$(PWD)/lib

# r_murmurc:
# 	make -C ./libultift all -j$(NPROCS)

$(minilibx-linux_A):
	$(MAKE) -C $(LIB_DIR)/minilibx-linux/

$(NAME): $(CMD_OBJS) $(OBJS) $(DEPENDENCIES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CMD_OBJS) $(libr) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@# @mv $@ $(OBJ_DIR)/

run: all
	@echo "===================================program======================================\n"
	./$(NAME)

clean:
	$(RM) $(OBJS) $(CMD_OBJS)
	@# make -C ./libultift clean
c: clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DEPENDENCIES)
# ifeq "$(os)" "Darwin"
# 		# make -C $(libs)/minilibx_opengl_20191021 clean
# else ifeq ($(os),Linux)
# 		make -C $(LIB_DIR)/minilibx-linux clean
# endif
# 		# make -C ./libultift fclean & make -C ./lib fclean & rm -f $(NAME) $(BNAME) & wait

f: fclean

re: fclean
	$(MAKE) all

t:
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(INC_DIR) test/testing.c test/token_test.c test/dollar_test.c test/equal_primitive.c $(SRCS) -o bin/test
	@./bin/test

.PHONY: all clean fclean re run t f c run m b bonus mandatory





# INC	=%%%%

# UNAME = $(shell uname)
# CC	= gcc
# ifeq ($(UNAME),FreeBSD)
# 	CC = clang
# endif

# NAME		= libmlx.a
# NAME_UNAME	= libmlx_$(UNAME).a

# SRC	= mlx_init.c mlx_new_window.c mlx_pixel_put.c mlx_loop.c \
# 	mlx_mouse_hook.c mlx_key_hook.c mlx_expose_hook.c mlx_loop_hook.c \
# 	mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
# 	mlx_int_wait_first_expose.c mlx_int_get_visual.c \
# 	mlx_flush_event.c mlx_string_put.c mlx_set_font.c \
# 	mlx_new_image.c mlx_get_data_addr.c \
# 	mlx_put_image_to_window.c mlx_get_color_value.c mlx_clear_window.c \
# 	mlx_xpm.c mlx_int_str_to_wordtab.c mlx_destroy_window.c \
# 	mlx_int_param_event.c mlx_int_set_win_event_mask.c mlx_hook.c \
# 	mlx_rgb.c mlx_destroy_image.c mlx_mouse.c mlx_screen_size.c \
# 	mlx_destroy_display.c

# OBJ_DIR = obj
# OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
# CFLAGS	= -O3 -I$(INC)

# all	: $(NAME)

# $(OBJ_DIR)/%.o: %.c
# 	@mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# $(NAME)	: $(OBJ)
# 	ar -r $(NAME) $(OBJ)
# 	ranlib $(NAME)
# 	cp $(NAME) $(NAME_UNAME)

# check: all
# 	@test/run_tests.sh

# show:
# 	@printf "NAME  		: $(NAME)\n"
# 	@printf "NAME_UNAME	: $(NAME_UNAME)\n"
# 	@printf "CC		: $(CC)\n"
# 	@printf "CFLAGS		: $(CFLAGS)\n"
# 	@printf "SRC		:\n	$(SRC)\n"
# 	@printf "OBJ		:\n	$(OBJ)\n"

# clean	:
# 	rm -rf $(OBJ_DIR)/ $(NAME) $(NAME_UNAME) *~ core *.core

# .PHONY: all check show clean
