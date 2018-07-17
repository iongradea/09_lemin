/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clean_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:32:58 by igradea           #+#    #+#             */
/*   Updated: 2017/07/25 13:38:24 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_format	*clean_precision_c_wc(t_format *opt)
{
	if ((opt->id == 'c' || opt->id == 'C') && opt->precision != NONE)
		opt->precision = NONE;
	return (opt);
}

t_format	*parsing_clean_special_c_b0(t_format *opt, char *s)
{
	if (opt->id == 'c' && s[0] == '\0' && opt->precision == 0)
		opt->precision = NONE;
	return (opt);
}
