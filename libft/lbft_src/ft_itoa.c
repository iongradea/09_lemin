/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 19:53:19 by igradea           #+#    #+#             */
/*   Updated: 2017/01/17 15:28:48 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	memory_needed(int n)
{
	int neg;
	int size;

	size = 0;
	neg = ((n > 0) ? 0 : 1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size + neg);
}

char		*ft_itoa(int nbr)
{
	unsigned int	n;
	int				size;
	char			*p;
	char			*dest;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	size = memory_needed(nbr);
	n = ((nbr < 0) ? -nbr : nbr);
	if (!(dest = (char*)malloc(sizeof(*dest) * (size + 1))))
		return (NULL);
	p = dest + size;
	*p-- = '\0';
	if (n == 0)
		*p = '0';
	while (n > 0)
	{
		*p-- = n % 10 + '0';
		n /= 10;
	}
	if (nbr < 0)
		*p = '-';
	return (dest);
}
