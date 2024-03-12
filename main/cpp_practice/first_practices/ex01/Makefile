CC            = clang++
CFLAGS        = -std=c++98
NAME          = phonebook
LIB           = 
SRC_DIR       = .
INC_DIR       = 
OBJ_DIR       = .
SRCS          = $(wildcard $(SRC_DIR)/*.cpp)
OBJS          = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES  =
os =  ${shell uname -s}
ifeq '$(os)' 'Darwin'
NPROCS  = $(shell sysctl -n hw.ncpu)
else ifeq '$(os)' 'Linux'
NPROCS  = $(shell nproc)
endif
MAKEFLAGS += -j$(NPROCS)
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
CFLAGS += -fsanitize=address
# CFLAGS += -fsanitize=thread
endif
test = 0
ifeq '$(test)' '1'
./$(attest) .
endif



all: $(DEPENDENCIES)
	@$(MAKE) $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
run: all
	./$(NAME)
clean:
	$(RM) $(OBJS) $(B_OBJ)
fclean: clean
	$(RM) $(NAME) & wait
re: fclean
	$(MAKE) all
.PHONY: all clean fclean re run