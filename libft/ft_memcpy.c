/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:08:25 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/23 18:06:18 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!destination && !source)
		return (0);
	d = (unsigned char*)destination;
	s = (unsigned char*)source;
	while (n--)
		*d++ = *s++;
	return (destination);
}
