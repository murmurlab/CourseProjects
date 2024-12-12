# 
# This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
# of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
# 

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = ft_printf_util.c ft_printf.c

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) *.o
	@echo "\033[92m compiling $@... \033[0m\n"
	# @sleep 1
	@echo "\033[92m $@ [OK!]\033[0m"
clean:
	@rm -f  *.o
	@echo "\033[31m rm .o files [KO!]\033[0m"
fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m rm .a [KO!]\033[0m"

re: fclean all

.PHONY : all clean fclean re
