/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:00:07 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/28 23:39:49 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strout;
	size_t	i;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	k = ft_strlen(s1);
	if (!(strout = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*(s1 + i))
	{
		*(strout + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + i - k))
	{
		*(strout + i) = *(s2 + i - k);
		i++;
	}
	*(strout + i) = '\0';
	return (strout);
}
