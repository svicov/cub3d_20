/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:49:12 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/23 18:09:34 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *destination, int c, size_t n)
{
	char	*p;

	p = (char*)destination;
	while (n--)
		*p++ = c;
	return (destination);
}
