/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clean_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:09:37 by igradea           #+#    #+#             */
/*   Updated: 2017/07/24 14:32:09 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_format	*over_comp_diez(t_format *opt)
{
	if (opt->id && ft_strchr("cdinpsuSDUC", opt->id))
		(opt->flags).diez = FALSE;
	return (opt);
}

t_format	*over_comp_0(t_format *opt)
{
	if ((opt->flags).minus == TRUE || opt->id == 'n')
		(opt->flags).zero = FALSE;
	if (opt->id && ft_strchr("diouixX", opt->id) && opt->precision != NONE)
		(opt->flags).zero = FALSE;
	return (opt);
}

t_format	*over_comp_sp(t_format *opt)
{
	if (opt->id && !(ft_strchr("aAdeEfFgGi", opt->id)))
		(opt->flags).space = FALSE;
	if ((opt->flags).plus == TRUE)
		(opt->flags).space = FALSE;
	return (opt);
}
