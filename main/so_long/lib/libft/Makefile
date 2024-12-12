# 
# This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
# of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
# 

FILES =				ft_memset.c ft_bzero.c ft_memcpy.c ft_striteri.c ft_memmove.c \
					ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
					ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
					ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJECTS =			$(FILES:.c=.o)
BONUS =				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
					ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJECTS =		$(BONUS:.c=.o)
GNL =				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c
GNL_OBJECTS =		$(GNL:.c=.o)
FT_PRINTF	=		ft_printf/ft_printf_util.c ft_printf/ft_printf.c
FT_PRINTF_OBJECTS =	$(FT_PRINTF:.c=.o)

MAKEFLAGS +=		-j$(NPROCS)

NAME        = libft.a
NAME_BONUS    = .libft_bonus.a
CFLAGS        = -Wall -Werror -Wextra
CC        = cc
AR        = ar -crs
RM        = rm -f

all: bonus

m: $(NAME)

b: bonus

${NAME}: ${OBJECTS}
	@echo "\033[92m compiling $@... \033[0m\n"
	@echo "\033[92m $@ [OK!]\033[0m"
	${AR} ${NAME} ${OBJECTS}

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${NAME} $(BONUS_OBJECTS) $(GNL_OBJECTS) $(FT_PRINTF_OBJECTS)
	${AR} ${NAME} $(BONUS_OBJECTS) $(GNL_OBJECTS) $(FT_PRINTF_OBJECTS)
	${AR} ${NAME_BONUS} ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS) $(GNL_OBJECTS) $(FT_PRINTF_OBJECTS)

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

re: fclean
	@$(MAKE) all

.PHONY: all bonus clean fclean re