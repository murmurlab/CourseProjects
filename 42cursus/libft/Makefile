srcs            = ${find . ! -name ft_lst*.c -name ft_*.c}
OBJS            = $(srcs:.c=.o)

BONUS			= ${wildcard ft_lst*.c}
BONUS_OBJS		= $(BONUS:.c=.o)

CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -I.

NAME			= libft.a

all:            $(NAME)

$(NAME):        $(OBJS)
				
				ar rcs $(NAME) $(OBJS)

clean: 
				$(RM) $(OBJS)

fclean:         clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:         all clean fclean re bonus