/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:47:11 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/29 00:31:42 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *scr, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!scr)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(scr));
	while (i < dstsize - 1 && scr[i] != '\0')
	{
		dst[i] = scr[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(scr));
}
