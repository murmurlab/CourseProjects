SRCS = ${wildcard ft_*.c}
CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
