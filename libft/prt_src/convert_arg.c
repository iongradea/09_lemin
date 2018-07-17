/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:07:30 by igradea           #+#    #+#             */
/*   Updated: 2017/07/24 14:17:36 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

intmax_t		arg_signed_modifier(va_list ap, t_format opt)
{
	intmax_t	i;

	if (opt.length.l == TRUE || opt.id == 'D')
		i = (intmax_t)va_arg(ap, long);
	else if (opt.length.h == TRUE)
		i = (intmax_t)(short)va_arg(ap, int);
	else if (opt.length.hh == TRUE)
		i = (intmax_t)(char)va_arg(ap, int);
	else if (opt.length.ll == TRUE)
		i = (intmax_t)va_arg(ap, long long);
	else if (opt.length.j == TRUE)
		i = va_arg(ap, intmax_t);
	else if (opt.length.z == TRUE)
		i = (intmax_t)va_arg(ap, ssize_t);
	else
		i = (intmax_t)va_arg(ap, int);
	return (i);
}

uintmax_t		arg_unsigned_modifier(va_list ap, t_format opt)
{
	uintmax_t	i;

	if (opt.length.l == TRUE || opt.id == 'U' || opt.id == 'O')
		i = (uintmax_t)va_arg(ap, unsigned long);
	else if (opt.length.hh == TRUE)
		i = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	else if (opt.length.h == TRUE)
		i = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
	else if (opt.length.ll == TRUE)
		i = (uintmax_t)va_arg(ap, unsigned long long);
	else if (opt.length.j == TRUE)
		i = va_arg(ap, uintmax_t);
	else if (opt.length.z == TRUE || opt.id == 'p')
		i = (uintmax_t)va_arg(ap, size_t);
	else
		i = (uintmax_t)va_arg(ap, unsigned int);
	return (i);
}
