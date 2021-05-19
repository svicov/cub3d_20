/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 05:31:11 by dbombur           #+#    #+#             */
/*   Updated: 2021/02/26 15:11:08 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t				ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(const char *str)
{
	char	*s;
	size_t	l;
	size_t	i;

	l = ft_strlen(str) + 1;
	i = 0;
	s = (char *)malloc(l * sizeof(*s));
	if (!s)
		return (NULL);
	if (s)
	{
		while (i < l)
		{
			s[i] = str[i];
			i++;
		}
		return (s);
	}
	return (NULL);
}

char				*ft_strchr(const char *s, int c)
{
	char	*res;
	size_t	i;
	size_t	l;

	res = NULL;
	i = 0;
	l = ft_strlen(s);
	while (i <= l)
	{
		if (s[i] == c)
		{
			res = (char *)&s[i];
			break ;
		}
		i++;
	}
	return (res);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (d == s)
		return (d);
	i = 0;
	if (d > s)
	{
		while (i++ < n)
			d[n - i] = s[n - i];
	}
	else
	{
		while (n-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
