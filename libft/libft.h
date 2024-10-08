/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:14:39 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/30 05:20:34 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strlen(char *s);

size_t				ft_strlcpy(char *dest, const char *src, size_t n);
int					ft_strlcat(char *dest, char *src, int n);
char				*ft_strchr(char *str, int c);
char				*ft_strrchr(char *str, int c);
char				*ft_strnstr(const char *f, const char *a, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(const char *str);
long int			ft_atol(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_calloc(size_t nmemb, size_t n);
char				*ft_strdup(char *str);

char				*ft_substr(char *str, unsigned int start, size_t n);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char *s1, char *set);
char				**ft_split(char *str, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char *str, char (*f)(unsigned int, char));
void				ft_striteri(char *str, void (*f)(unsigned int, char*));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
size_t				ft_count_number(const char *str, char c);

char				*get_next_line(int fd);
char				*read_and_store(int fd, char *stash);
char				*update_stash(char	*stash, char *buff);
char				*extract_line(char *stash);
char				*trim_stash(char *stash);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(char *str, int c );
char				*ft_strndup(char *str, int n);
int					ft_putstr(char *str);
int					ft_putchar(char c);
int					ft_putnbr(int n);
int					ft_putnbr_u(unsigned int n);
int					ft_check_format(char type, va_list args);
int					ft_printf(const char *format, ...);
int					ft_putnbr_xx(unsigned long long int n, char type);
int					ft_putadress_p(unsigned long long int n);

#endif
