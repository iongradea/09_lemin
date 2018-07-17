/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:41:59 by igradea           #+#    #+#             */
/*   Updated: 2017/07/25 13:29:52 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		is_octal_conv(t_format opt)
{
	return (opt.id == 'o' || opt.id == 'O');
}

int		is_hexa_conv(t_format opt)
{
	return (opt.id == 'x' || opt.id == 'X' || opt.id == 'p');
}

int		is_signed_conv(t_format opt)
{
	if (opt.id == 'd' || opt.id == 'i' || opt.id == 'D')
		return (TRUE);
	return (FALSE);
}

int		is_unsigned_conv(t_format opt)
{
	if (is_octal_conv(opt) || is_hexa_conv(opt) || opt.id == 'u'
			|| opt.id == 'U' || opt.id == 'b')
		return (TRUE);
	return (FALSE);
}

int		is_string_conv(t_format opt)
{
	if (opt.id == 's' || opt.id == 'S')
		return (TRUE);
	return (FALSE);
}
