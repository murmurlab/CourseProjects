srcs            =	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c	ft_memmove.c \
					ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_strtrim.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_striteri.c ft_lstnew.c \
					ft_lstsize.c ft_lstadd_front.c
OBJS            = $(srcs:.c=.o)
CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -I.
nam				= file.f
dsss			= libft.a
all:            $(dsss)
libft.a:        $(OBJS)
	ar rcs $(dsss) $(OBJS)
clean: $(dsss)
	$(RM) $(OBJS)
fclean:         clean
	$(RM) $(NAME)
re:				fclean all
fixx:			$(nam)
	echo finished
$(nam):
	echo	nam executed
libft.c:
	echo libft
rrr:			*.o
	echo	aaaaaa

.PHONY:         all clean fclean re