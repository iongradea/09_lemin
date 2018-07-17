/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:05:24 by igradea           #+#    #+#             */
/*   Updated: 2017/07/24 14:23:27 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	flags_opt(const char *fmt, int *i, t_flags *flags)
{
	while (fmt[*i] && ft_strchr("-+ 0#", fmt[*i]))
	{
		if (fmt[*i] == '-')
			flags->minus = TRUE;
		if (fmt[*i] == '+')
			flags->plus = TRUE;
		if (fmt[*i] == ' ')
			flags->space = TRUE;
		if (fmt[*i] == '0')
			flags->zero = TRUE;
		if (fmt[*i] == '#')
			flags->diez = TRUE;
		(*i)++;
	}
	return (TRUE);
}

static int	length_opt(const char *fmt, int *i, t_length *len)
{
	while (fmt[*i] && ft_strchr("hljz", fmt[*i]))
	{
		if (fmt[*i] && fmt[*i] == 'h')
			length_opt_h(fmt, i, len);
		if (fmt[*i] && fmt[*i] == 'l')
			length_opt_l(fmt, i, len);
		if (fmt[*i] && fmt[*i] == 'j')
		{
			len->j = TRUE;
			(*i)++;
		}
		if (fmt[*i] && fmt[*i] == 'z')
		{
			len->z = TRUE;
			(*i)++;
		}
	}
	return (TRUE);
}

static int	conv_opt(const char *fmt, int *i, t_format *opt)
{
	opt->id = fmt[*i];
	(*i)++;
	return (*i);
}

int			parser(const char *fmt, int *i, t_format *opt, va_list ap)
{
	while (fmt[*i])
	{
		if (fmt[*i] && ft_strchr("sSpdDioOuUxXcCbn", fmt[*i]))
			return (conv_opt(fmt, i, opt));
		else if (fmt[*i] && ft_strchr("-+0 #", fmt[*i]))
			flags_opt(fmt, i, &(opt->flags));
		else if (fmt[*i] && (ft_isdigit(fmt[*i]) || fmt[*i] == '*'))
			min_width_opt(fmt, i, opt, ap);
		else if (fmt[*i] && fmt[*i] == '.')
			precision_opt(fmt, i, opt, ap);
		else if (fmt[*i] && ft_strchr("hljz", fmt[*i]))
			length_opt(fmt, i, &(opt->length));
		else
		{
			opt->unspecified = fmt[*i];
			(*i)++;
			return (*i);
		}
	}
	return (ERRPR);
}
