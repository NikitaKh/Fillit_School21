/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:10:17 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/20 17:20:04 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>

# include <string.h>

# include <stdlib.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);

char				*ft_strcat(char *str1, const char *str2);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strdup(const char *s1);

size_t				ft_strlen(const char *str);

char				*ft_strncpy(char *dest, const char *src, size_t len);

void				ft_putchar(char c);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

void				*ft_memset(void *str, int c, size_t n);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strstr(const char *s1, const char *s2);

char				*ft_strnstr(const char *s1, const char *s2, size_t len);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

void				ft_putstr(char const *str);

void				ft_putnbr(int nb);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

void				ft_putendl(char const *s);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

int					ft_count_w(const char *s, char c);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_count_num(long nb);

char				*ft_itoa(int n);

char				**ft_strsplit(char const *s, char c);

size_t				ft_miss_space(const char *str);

size_t				ft_len(const char *s, char c);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif