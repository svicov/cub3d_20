/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:34:10 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/26 21:07:16 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*pmem;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(str);
	pmem = malloc((l + 1) * sizeof(char));
	if (NULL == pmem)
		return (NULL);
	while (i < l)
	{
		*(pmem + i) = *(str + i);
		i++;
	}
	*(pmem + i) = '\0';
	return (pmem);
}
