/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 12:01:26 by igradea           #+#    #+#             */
/*   Updated: 2017/01/10 19:12:58 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putnbr(-2);
			ft_putnbr(147483648);
		}
		else
		{
			nb = -nb;
			ft_putchar('-');
			ft_putnbr(nb);
		}
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
		else
			ft_putchar(nb + '0');
	}
}
