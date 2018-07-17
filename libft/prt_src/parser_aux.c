/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 21:53:18 by igradea           #+#    #+#             */
/*   Updated: 2017/07/24 14:24:03 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	min_width_opt(const char *fmt, int *i, t_format *opt, va_list ap)
{
	int	n;

	n = 0;
	if (fmt[*i] && ft_isdigit(fmt[*i]))
		opt->min_width = ft_atoi_prtf(fmt, i);
	else
	{
		n = va_arg(ap, int);
		if (n < 0)
			(opt->flags).minus = TRUE;
		opt->min_width = ft_abs(n);
		(*i)++;
	}
	return (TRUE);
}

int	precision_opt(const char *fmt, int *i, t_format *opt, va_list ap)
{
	int	n;

	n = NONE;
	(*i)++;
	if (fmt[*i] && ft_isdigit(fmt[*i]))
		opt->precision = ft_atoi_prtf(fmt, i);
	else if (fmt[*i] && fmt[*i] == '*')
	{
		n = va_arg(ap, int);
		if (n >= 0)
			opt->precision = ft_abs(n);
		(*i)++;
	}
	else
		opt->precision = 0;
	return (TRUE);
}

int	length_opt_h(const char *fmt, int *i, t_length *len)
{
	if (fmt[*i] && fmt[*i + 1] && fmt[*i] == 'h' && fmt[*i + 1] == 'h')
	{
		len->hh = TRUE;
		*i += 2;
	}
	else
	{
		len->h = TRUE;
		(*i)++;
	}
	return (TRUE);
}

int	length_opt_l(const char *fmt, int *i, t_length *len)
{
	if (fmt[*i] && fmt[*i + 1] && fmt[*i] == 'l' && fmt[*i + 1] == 'l')
	{
		len->ll = TRUE;
		*i += 2;
	}
	else
	{
		len->l = TRUE;
		(*i)++;
	}
	return (TRUE);
}
