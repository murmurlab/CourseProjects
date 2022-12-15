SRCS            = ft_split.c ft_strlen.c
OBJS            = $(SRCS:.c=.o)
CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -I.
NAME            = libft.a
all:            $(NAME)
$(NAME):        $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean:         clean
	$(RM) $(NAME)re:             fclean $(NAME).PHONY:         all clean fclean re