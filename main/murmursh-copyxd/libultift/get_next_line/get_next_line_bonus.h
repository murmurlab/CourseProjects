/**
 * This work © 2023 by murmurlab is licensed under CC BY-SA 4.0. To view a copy 
 * of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_gnl_b(char *buf);
char	*get_next_line_b(int fd);
char	*get_new_line_b(char *buffer);
char	*first_read_b(int fd, char *buffer);
int		find_nl_char_b(char *buffer);
char	*strjoin_gnl_b(char *buffer, char *new_buffer);
char	*get_new_buffer_b(char *buffer);

#endif
