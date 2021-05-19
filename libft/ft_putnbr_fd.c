/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:05:27 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/29 03:50:36 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_opr_step(int nc)
{
	int			k;

	k = 1;
	while (nc > 9)
	{
		nc = nc / 10;
		k = k * 10;
	}
	return (k);
}

void			ft_putnbr_fd(int n, int fd)
{
	int			i;

	if (n == 0)
	{
		ft_putstr_fd("0", fd);
	}
	else if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		i = ft_opr_step(n);
		while (i > 0)
		{
			ft_putchar_fd((n / i + 48), fd);
			n = n - ((n / i) * i);
			i = i / 10;
		}
	}
}
