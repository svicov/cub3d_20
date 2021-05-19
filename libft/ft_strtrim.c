/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:24:01 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/29 01:09:10 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s || !set)
		return (NULL);
	l = ft_strlen(s);
	while (*(s + i) && ft_strchr(set, *(s + i)))
		i++;
	while ((l > i) && ft_strchr(set, *(s + l)))
		l--;
	l = l - i + 1;
	return (ft_substr(s, i, l));
}
