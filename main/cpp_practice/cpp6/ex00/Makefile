CC				= clang++
CXXFLAGS        = -std=c++98 -pedantic

LXXFLAGS		= 
RUNFLAGS		=

NAME			= program
LIB				= 
SRC_DIR			= .
INC_DIR			= 
OBJ_DIR			= .
SRCS			= $(wildcard $(SRC_DIR)/*.cpp)
OBJS			= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES	=

os =  ${shell uname -s}
ifeq '$(os)' 'Darwin'
NPROCS  = $(shell sysctl -n hw.ncpu)
else ifeq '$(os)' 'Linux'
NPROCS  = $(shell nproc)
endif
# MAKEFLAGS += -j$(NPROCS)
gnu = 0
ifeq '$(gnu)' '1'
CXXFLAGS += $(stdcxx_cxxflags)
LXXFLAGS += $(stdcxx_lxxflags)
endif

w = 1
ifeq '$(w)' '1'
CXXFLAGS += -Wextra -Werror -Wall
endif
debug = 1
ifeq '$(debug)' '1'
CXXFLAGS += -g
endif
asan = 0
ifeq '$(asan)' '1'
RUNFLAGS += ASAN_OPTIONS='detect_leaks=1'
LXXFLAGS += -lasan #-fsanitize=address
# LXXFLAGS += -fsanitize=thread
endif
test = 0
ifeq '$(test)' '1'
./$(attest) .
endif

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
all: $(DEPENDENCIES)
	@$(MAKE) $(NAME)
$(NAME): $(OBJS)
	$(CC) $(LXXFLAGS) $(OBJS) -o $(NAME)
run: re
	$(RUNFLAGS) ./$(NAME) 
clean:
	@$(RM) $(OBJS) $(B_OBJ)
fclean: clean
	@$(RM) $(NAME) & wait
re: fclean
	$(MAKE) all
.PHONY: all clean fclean re run
