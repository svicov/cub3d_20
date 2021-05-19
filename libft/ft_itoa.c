/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:03:44 by dbombur           #+#    #+#             */
/*   Updated: 2020/11/28 21:31:28 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_opr_raz(int nc)
{
	int			k;

	k = 0;
	while (nc != 0)
	{
		nc = nc / 10;
		k++;
	}
	return (k);
}

static char		*ft_vvnull(void)
{
	char		*st0;

	if (!(st0 = (char *)malloc(2 * sizeof(char))))
		return (NULL);
	*st0 = '0';
	*(st0 + 1) = '\0';
	return (st0);
}

static	char	*ft_vv_intmin(void)
{
	char		*str;

	if (!(str = (char *)malloc(12 * sizeof(char))))
		return (NULL);
	*(str + 0) = '-';
	*(str + 1) = '2';
	*(str + 2) = '1';
	*(str + 3) = '4';
	*(str + 4) = '7';
	*(str + 5) = '4';
	*(str + 6) = '8';
	*(str + 7) = '3';
	*(str + 8) = '6';
	*(str + 9) = '4';
	*(str + 10) = '8';
	*(str + 11) = '\0';
	return (str);
}

static	char	*ft_ito_(int n)
{
	int			razr;
	char		*st_;
	int			z;

	z = 0;
	razr = ft_opr_raz(n);
	if (n < 0)
	{
		z = 1;
		n = -n;
	}
	if (!(st_ = (char *)malloc((razr + z + 1))))
		return (NULL);
	if (z)
		*st_ = '-';
	*(st_ + razr + z) = '\0';
	while (0 < razr)
	{
		*(st_ + razr-- - 1 + z) = (n % 10 + '0');
		n = n / 10;
	}
	return (st_);
}

char			*ft_itoa(int n)
{
	char		*str;

	if (n == -2147483648)
	{
		str = ft_vv_intmin();
		return (str);
	}
	if (n == 0)
	{
		str = ft_vvnull();
		return (str);
	}
	str = ft_ito_(n);
	return (str);
}
