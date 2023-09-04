CC = 					clang
CFLAGS = 				-std=c99 -g -Wall -Werror -Werror
os = ${shell uname -s}
src = ${shell find . -maxdepth 1 -name '*.c'}
NAME = ${src:.c=.o}
program = sorter
# MAKEFLAGS += -j$(NPROCS)

all: $(NAME) murmurlibc
ifeq '$(os)' 'Darwin'
	$(CC) $(CFLAGS) -o $(program) $(NAME) lib/murmurlibc.a
else ifeq '$(os)' 'Linux'
	$(CC) $(CFLAGS) -o $(program) $(NAME) lib/murmurlibc.a
endif
$(NAME):

murmurlibc:
	make -C lib
clean:
	find . -maxdepth 1 -name "*.o" -exec rm {} +
fclean: clean
	make -C lib clean
	rm -f $(program)
re: fclean all

.PHONY: re fclean clean murmurlibc all