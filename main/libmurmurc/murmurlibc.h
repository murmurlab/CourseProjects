
// ahbasara

#ifndef MURMURLIBC_H
# define MURMURLIBC_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	void			*content;
	int				i;
	struct s_list	*next;
}	t_list;

typedef struct s_wasd
{
	int				*i;
	struct s_wasd	*prev;
	struct s_wasd	*ww;
	struct s_wasd	*aa;
	struct s_wasd	*ss;
	struct s_wasd	*dd;
}	t_wasd;

char					*multi_get_line(int fd);
char					*read_to_left_str(int fd, char *left_str);
char					*get_line(char *left_str);
char					*new_left_str(char *left_str);
//UTILS
char					*gnl_strchr(const char *s, int c);
char					*gnl_stradd(char *s1, char *s2);
size_t					gnl_strlen(const char *s);

unsigned long long int	x(unsigned long long int i, char *s, char m);
unsigned long long int	q(char *s, char p, char kar);
int						spaghetti(const char *s2, ...);
unsigned long long int	xp(unsigned long long int i, char *s, char m);
unsigned long long int	qp(char *s, char p, char kar);

void					check_format(va_list argl, \
							const char **str, int *len);
int						p(const char *str, ...);

t_list					*llnew(void *content);
void					lladd(t_list **lst, t_list *new);
int						lllen(t_list *lst);
t_list					*llend(t_list *lst);
void					llprepend(t_list **lst, t_list *new);
void					lldel(t_list **lst, void (*del)(void **));
void					llpop(t_list **lst, void (*del)(void **));
void					llclr(t_list **lst, void (*del)(void **));
void					lliter(t_list *lst, void (*f)(void *, void *), void *p);
t_list					*llmap(t_list *lst, void *(*f)(void *)\
						, void (*del)(void **));
t_wasd					*ll4new(void *content);
t_list					*findex(t_list *p, int f);

char					*x_itoa(int n);
int						isalpha(int c);
int						isnum(int c);
int						isalnum(int c);
int						isascii(int c);
int						isprint(int c);
int						camel(int c);
int						gnome(int c);

void					freedom(void **adr);
void					*callocate(size_t count, size_t size);
void					*xmemset(void *b, int c, size_t len);
void					memnull(void *s, size_t n);
void					*xmemcpy(void *dst, const void *src, size_t n);
void					*memmov(void *dest, const void *src, size_t n);
int						xmemcmp(const void *s1, const void *s2, size_t n);
void					*xmemchr(const void *s, int c, size_t n);

char					*xstrchr(const char *s, int c);
char					*strrchr(const char *s, int c);
int						strncmp(const char *s1, const char *s2, size_t n);
char					*strnstr(const char *haystack \
						, const char *needle, size_t len);
int						x_atoi(const char *str);
char					*strcln(const char *s1);
char					*strcut(char const *s, \
						unsigned int start, size_t len);
char					*stradd(char const *s1, const char *s2);
char					*strtrim(char const *s1, char const *set);
size_t					xstrlen(const char *s);
size_t					strclen(const char *s, char c);
size_t					strclen2(const char *s, char c);
size_t					xstrlcpy(char *dst, const char *src, size_t dstsize);
size_t					xstrlcat(char *dst, const char *src, size_t dstsize);
char					*strmap(char const *s, \
						char (*f)(unsigned int, char));
void					striter(char *s, void (*f)(unsigned int, char *, void \
						*), void *p);

char					**seperate(char const *s, char c);

void					char2fd(char c, int fd);
void					str2fd(char *s, int fd);
void					eol2fd(char *s, int fd);
void					num2fd(int n, int fd);

#endif
