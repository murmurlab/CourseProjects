CC		= cc
DBG		= ""
CFLAGS	= $(DBG) -Wall -Wextra -Werror
SRC		= $(shell find . -maxdepth 1 -not -name "*_bonus.c" -a -name "*.c")
BSRC	= $(wildcard *_bonus.c)
OBJ		= $(SRC:.c=.o)
BOBJ	= $(BSRC:.c=.o)
libft	= ./libft/libft

ITER	= $(OBJ:.o=)
BITER	= $(BOBJ:.o=)

all: mandatory bonus

mandatory:		libftprintf libft $(OBJ) $(ITER)

$(ITER): 
	${CC} ${CFLAGS} $@.o ./libft/libft.a ./ft_printf/spagetti/libftprintf.a -o $@
$(BITER): 
	${CC} ${CFLAGS} $@.o ./libft/libft.a ./ft_printf/spagetti/libftprintf.a -o $@

bonus:		libftprintf libft $(BOBJ) $(BITER)

libft:
	make -C ./libft re
libftprintf:
	make -C ./ft_printf/spagetti re
clean:
	rm -fr $(OBJ) $(BOBJ)
fclean:		clean
	rm -fr client server client_bonus server_bonus
re:			fclean all

.PHONY: libft libftprintf all clean fclean re mandatory bonus