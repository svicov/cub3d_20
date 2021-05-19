/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:35:38 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/28 23:23:54 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int				word_count(char const *s, char c)
{
	int					words;
	char				prev;

	words = 0;
	prev = c;
	while (*s)
	{
		if (prev == c && *s != c)
			words++;
		prev = *s;
		s++;
	}
	return (words);
}

static	char	const	*find_begin(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static	char	const	*find_end(char const *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

static	char			*clone(char const *s, int n)
{
	char				*result;
	char				*p;

	result = (char*)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	p = result;
	while (n--)
		*p++ = *s++;
	*p = 0;
	return (result);
}

char					**ft_split(char const *s, char c)
{
	int					words;
	char				**arr;
	char				**current;
	char const			*begin;
	char				*str;

	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	arr = (char**)malloc(sizeof(char*) * (words + 1));
	if (!arr)
		return (NULL);
	current = arr;
	while (*s)
	{
		begin = find_begin(s, c);
		if (!*begin)
			break ;
		s = find_end(begin, c);
		str = clone(begin, s - begin);
		*current++ = str;
	}
	*current = NULL;
	return (arr);
}
