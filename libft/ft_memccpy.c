/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:15:32 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/23 18:04:08 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)destination;
	s = (unsigned char*)source;
	while (n--)
	{
		*d = *s;
		if (*d == (unsigned char)c)
			return (++d);
		d++;
		s++;
	}
	return (0);
}
