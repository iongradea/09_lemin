/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 12:01:26 by igradea           #+#    #+#             */
/*   Updated: 2017/01/11 14:13:36 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putnbr_fd(-2, fd);
			ft_putnbr_fd(147483648, fd);
		}
		else
		{
			nb = -nb;
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(nb, fd);
		}
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd(nb % 10 + '0', fd);
		}
		else
			ft_putchar_fd(nb + '0', fd);
	}
}
