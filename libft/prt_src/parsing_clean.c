/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:41:31 by igradea           #+#    #+#             */
/*   Updated: 2017/07/25 13:36:48 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_format	*clean_fmt_diouxp_xdou(t_format *opt)
{
	if ((opt->length).l == TRUE && opt->id == 'd')
	{
		opt->id = 'D';
		reset_length(opt);
	}
	else if ((opt->length).l == TRUE && opt->id == 'o')
	{
		opt->id = 'O';
		reset_length(opt);
	}
	else if ((opt->length).l == TRUE && opt->id == 'u')
	{
		opt->id = 'U';
		reset_length(opt);
	}
	else if (opt->id && ft_strchr("DOUp", opt->id))
		reset_length(opt);
	else if (opt->id && ft_strchr("diouxX", opt->id))
		set_max_length(opt);
	return (opt);
}

static t_format	*clean_fmt_c_s(t_format *opt)
{
	if (opt->id && ft_strchr("csCS", opt->id))
	{
		if ((opt->length).l == TRUE && opt->id == 'c')
			opt->id = 'C';
		else if ((opt->length).l == TRUE && opt->id == 's')
			opt->id = 'S';
		reset_length(opt);
	}
	return (opt);
}

static t_format	*clean_unspecified(t_format *opt)
{
	if (opt->id == '\0' && opt->unspecified != '\0')
		set_max_length(opt);
	if (opt->id == '\0' && opt->precision == 0)
		opt->precision = 1;
	return (opt);
}

t_format		*parsing_clean(t_format *opt)
{
	over_comp_diez(opt);
	over_comp_0(opt);
	over_comp_sp(opt);
	clean_fmt_diouxp_xdou(opt);
	clean_fmt_c_s(opt);
	clean_unspecified(opt);
	clean_precision_c_wc(opt);
	return (opt);
}
