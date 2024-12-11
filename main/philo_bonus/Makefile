CC				= cc

LXXFLAGS		=
RUNFLAGS		=	
# MAKEFLAGS +=			-j$(NPROCS)

EXE_DIR			= 
ROOT			= .
NAME			= philo_bonus
TEST			= 
LIB				= $(ROOT)/lib
CMD_DIR			= $(ROOT)/
SRC_DIR			= $(ROOT)/
INC_DIR			= $(ROOT)/
INCS			=	$(INC_DIR)/philo_bonus.h \
					# $(INC_DIR)/
OBJ_DIR			= .
SRCS			=	$(wildcard $(SRC_DIR)/*.cpp) \
					$(SRC_DIR)/utils_bonus.c \
					$(SRC_DIR)/init_bonus.c
OBJS			= $(SRCS:%.c=%.o) #$(SRCS:%.cpp=%.o)
CMD_so_long		= $(CMD_DIR)/$(NAME).o
# CMD_IRCTEST		= $(CMD_DIR)/$(TEST).o
CMDS			= $(CMD_so_long) $(CMD_IRCTEST)

# minilibx_opengl_20191021
# minilibx_mms_20200219
LIB_mlx_dir		=	$(LIB)/minilibx_opengl_20191021
LIB_mlx_inc		=	-I $(LIB_mlx_dir)/
LIB_mlx_dylib	=	$(LIB_mlx_dir)/libmlx.dylib
LIB_mlx_ld		=	-L $(LIB_mlx_dir)/ -l mlx -framework OpenGL -framework AppKit -lz

LIB_ft_dir		=	$(LIB)/libft
LIB_ft_inc		=	-I $(LIB_ft_dir)/
LIB_ft_ld		=	-L $(LIB_ft_dir)/ -l ft

DEPENDENCIES	=	#libmlx libft
LIBS			=	 #$(LIB_mlx_dylib)

LXXFLAGS		+=	 #$(LIB_mlx_dylib)
CXXFLAGS        +=	-std=c99 -pedantic -I $(INC_DIR)
RUNFLAGS		+=	#DYLD_LIBRARY_PATH=$(LIB_mlx_dir)

# ======================== multithread compile ========================
os =  ${shell uname -s}
ifeq '$(os)' 'Darwin'
NPROCS  = $(shell sysctl -n hw.ncpu)
else ifeq '$(os)' 'Linux'
NPROCS  = $(shell nproc)
endif
# MAKEFLAGS += -j$(NPROCS)

# ======================== gnu lib / inc ========================
gnu = 0
ifeq '$(gnu)' '1'
CXXFLAGS += $(stdcxx_cxxflags)
LXXFLAGS += $(stdcxx_lxxflags)
endif

# ======================== flag arg ========================
w = 1
ifeq '$(w)' '1'
CXXFLAGS += -Wextra -Werror -Wall
endif
debug = 1
ifeq '$(debug)' '1'
CXXFLAGS += -g
endif
asan = 1
ifeq '$(asan)' '1'
# RUNFLAGS += ASAN_OPTIONS='detect_leaks=1'
LXXFLAGS += #-fsanitize=thread #-lasan
# LXXFLAGS += -fsanitize=thread
endif
test = 0
ifeq '$(test)' '1'
./$(attest) .
endif

all: $(DEPENDENCIES)
	$(MAKE) $(NAME) $(TEST)

.PHONY: all clean fclean re run

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
%.o: %.c
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(CMD_so_long) $(INCS) $(LIBS)
	$(CC) $(LXXFLAGS) $(CMD_so_long) $(OBJS) -o $(NAME)
# $(TEST): $(OBJS) $() $(INCS) \
	# $(CC) $(LXXFLAGS) $() $(OBJS) -o $(TEST)

# ===================== libs ========================
libmlx:
	$(MAKE) -C $(LIB_mlx_dir)
libft:
	$(MAKE) -C $(LIB_ft_dir)

# ===================== auto ========================
run: all
	$(RUNFLAGS) ./$(NAME) $(args) ./maps/test.ber
test: all
	$(RUNFLAGS) vg --leak-check=full ./$(NAME) $(args)

# export DYLD_LIBRARY_PATH=./lib/minilibx_mms_20200219; make w=0 re && vg --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks.log --suppressions=mlx.supp ./so_long ./../so_long/maps/map.ber

# ===================== sources ========================
clean:
	$(RM) $(OBJS) $(B_OBJ) $(CMDS)
fclean: clean
	$(RM) $(NAME) $(TEST) & wait
re: fclean
	$(MAKE) all
