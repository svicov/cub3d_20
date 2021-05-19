/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:25:54 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/26 20:29:23 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t n, size_t size)
{
	void	*pmem;

	pmem = malloc(n * size);
	if (pmem != NULL)
		ft_bzero(pmem, n * size);
	return (pmem);
}
