/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iongradea <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:48:57 by iongradea         #+#    #+#             */
/*   Updated: 2017/07/25 13:12:44 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		set_pos(t_pos_size *ps, t_format opt)
{
	if (opt.flags.minus == TRUE)
	{
		ps->pos_prep = 0;
		ps->pos_prec = ps->size_prep;
		ps->pos_str = ps->pos_prec + ps->size_prec;
	}
	else if (opt.flags.zero == TRUE)
	{
		ps->pos_prep = 0;
		ps->pos_str = ps->size_total - ps->size_str;
	}
	else
	{
		ps->pos_str = ps->size_total - ps->size_str;
		ps->pos_prec = ps->pos_str - ps->size_prec;
		ps->pos_prep = ps->pos_prec - ps->size_prep;
	}
}

void		set_background(t_pos_size *ps, t_format opt)
{
	ft_memset(ps->total, ' ', (size_t)ps->size_total);
	if (opt.flags.zero == TRUE)
		ft_memset(ps->total, '0', (size_t)ps->size_total);
	else if (ps->size_prec != FALSE)
		ft_memset(ps->total + ps->pos_prec, '0', (size_t)ps->size_prec);
}

static void	set_size_signed(t_pos_size *ps, t_format opt, t_base baz,
		intmax_t n)
{
	int	len;

	len = 1;
	if (n == 0 && opt.precision == 0)
		ps->size_str = 0;
	else
	{
		while (n >= baz.base || n <= -baz.base)
		{
			n = n / baz.base;
			len++;
		}
		ps->size_str = len;
	}
	init_int_prepend(ps->prep, opt, n);
	ps->size_prep = ft_strlen(ps->prep);
	ps->size_prec = opt.precision > len ? opt.precision - len : 0;
	ps->size_total = ft_max(opt.min_width,
			ps->size_prec + ps->size_prep + ps->size_str);
}

int			d_convert(t_pos_size *ps, t_format opt, va_list ap)
{
	t_base		baz;
	intmax_t	n;

	n = arg_signed_modifier(ap, opt);
	init_struct_ps(ps);
	init_struct_base(&baz, opt);
	set_size_signed(ps, opt, baz, n);
	set_pos(ps, opt);
	if (!(ps->total = (char*)malloc(sizeof(char) * (ps->size_total + 1))))
		return (ERRPR);
	set_background(ps, opt);
	ft_memcpy(ps->total + ps->pos_prep, ps->prep, ft_strlen(ps->prep));
	ft_itoa_base_intmax(ps, baz, n);
	return (TRUE);
}
