/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:57:18 by dbombur           #+#    #+#             */
/*   Updated: 2020/12/02 07:04:08 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int ch)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(str);
	if (ch == '\0')
		return ((char*)(str + l));
	while (*(str + i) != '\0')
	{
		if (*(str + i) == ch)
			return ((char*)(str + i));
		i++;
	}
	return (NULL);
}
