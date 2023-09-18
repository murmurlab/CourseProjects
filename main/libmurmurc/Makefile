srcs            = $(shell find . -name "*.c")

CC              = cc
RM              = rm -f
CFLAGS          = -std=c99 -g -Wall -Wextra -Werror -I.

OBJS            = $(srcs:.c=.o)

NAME			= libmurmurc.a

all:            $(NAME)

$(NAME):        $(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:         all clean fclean re