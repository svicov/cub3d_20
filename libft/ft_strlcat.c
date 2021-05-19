/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:00:00 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/29 00:36:23 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *scr, size_t dstsize)
{
	size_t a;
	size_t b;
	size_t c;

	a = 0;
	while (dst[a] != 0)
		a++;
	b = 0;
	while (scr[b] != 0)
		b++;
	if (dstsize <= a)
		b += dstsize;
	else
		b += a;
	c = 0;
	while (scr[c] != 0 && a + 1 < dstsize)
		dst[a++] = scr[c++];
	dst[a] = 0;
	return (b);
}
