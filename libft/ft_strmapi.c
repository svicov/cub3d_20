/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:15:27 by dbombur           #+#    #+#             */
/*   Updated: 2020/12/02 06:01:12 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	l;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	if (!(str = malloc((l + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < l)
	{
		*(str + i) = (*f)(i, *(s + i));
		i++;
	}
	*(str + l) = '\0';
	return (str);
}
