SRCS            = ft_substr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_calloc.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_tolower.c
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