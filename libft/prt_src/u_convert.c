/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:05:25 by igradea           #+#    #+#             */
/*   Updated: 2017/07/22 12:14:40 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	set_size_unsigned(t_pos_size *ps, t_format opt,
		t_base baz, uintmax_t n)
{
	int	len;

	len = 1;
	if (n == 0 && opt.precision == 0)
		ps->size_str = 0;
	else
	{
		while (n >= (unsigned int)baz.base)
		{
			n = n / (unsigned int)baz.base;
			len++;
		}
		ps->size_str = len;
	}
	init_uint_prepend(ps->prep, opt, n);
	ps->size_prep = ft_strlen(ps->prep);
	ps->size_prec = opt.precision > len ? opt.precision - len : 0;
	ps->size_total = ft_max(opt.min_width,
			ps->size_prec + ps->size_prep + ps->size_str);
}

int			u_convert(t_pos_size *ps, t_format opt, va_list ap)
{
	t_base		baz;
	uintmax_t	n;

	n = arg_unsigned_modifier(ap, opt);
	init_struct_ps(ps);
	init_struct_base(&baz, opt);
	set_size_unsigned(ps, opt, baz, n);
	set_pos(ps, opt);
	if (!(ps->total = (char*)malloc(sizeof(char) * (ps->size_total + 1))))
		return (ERRPR);
	set_background(ps, opt);
	ft_memcpy(ps->total + ps->pos_prep, ps->prep, ft_strlen(ps->prep));
	ft_itoa_base_uintmax(ps, baz, n);
	return (TRUE);
}
