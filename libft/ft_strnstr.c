/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:00:25 by dbombur           #+#    #+#             */
/*   Updated: 2020/12/03 15:51:08 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(lit);
	if (l == 0)
		return ((char *)big);
	i = 0;
	while (big + i <= big + len - l)
	{
		if (ft_strncmp((big + i), lit, l) == 0)
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
