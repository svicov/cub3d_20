/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:01:17 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/29 00:01:29 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define INT_MAX 2147483647
# include <stdlib.h>
# include <unistd.h>

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_memccpy(void *destination, const void *source, int c, size_t n);
void		*ft_memchr(const void *arr, int c, size_t n);
int			ft_memcmp(const void *arr1, const void *arr2, size_t n);
void		*ft_memcpy(void *destination, const void *source, size_t n);
void		*ft_memmove(void *destination, const void *source, size_t n);
void		*ft_memset(void *destination, int c, size_t n);
char		*ft_strchr(const char *str, int ch);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int ch);
int			ft_toupper(int c);
int			ft_tolower(int ch);
void		*ft_calloc(size_t n, size_t size);
char		*ft_strdup(const char *str);
int			ft_isprint(int ch);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *str, int ch);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
#endif
