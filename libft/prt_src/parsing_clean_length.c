/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clean_length.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:33:10 by igradea           #+#    #+#             */
/*   Updated: 2017/07/25 13:14:07 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_format	*reset_length(t_format *opt)
{
	(opt->length).h = FALSE;
	(opt->length).hh = FALSE;
	(opt->length).l = FALSE;
	(opt->length).ll = FALSE;
	(opt->length).j = FALSE;
	(opt->length).z = FALSE;
	return (opt);
}

t_format	*set_max_length_hh_h_z(t_format *opt)
{
	if ((opt->length).hh == TRUE)
	{
		reset_length(opt);
		(opt->length).hh = TRUE;
	}
	else if ((opt->length).h == TRUE)
	{
		reset_length(opt);
		(opt->length).h = TRUE;
	}
	else if ((opt->length).z == TRUE)
	{
		reset_length(opt);
		(opt->length).z = TRUE;
	}
	return (opt);
}

t_format	*set_max_length(t_format *opt)
{
	if ((opt->length).j == TRUE)
	{
		reset_length(opt);
		(opt->length).j = TRUE;
	}
	else if ((opt->length).ll == TRUE)
	{
		reset_length(opt);
		(opt->length).ll = TRUE;
	}
	else if ((opt->length).l == TRUE)
	{
		reset_length(opt);
		(opt->length).l = TRUE;
	}
	else if ((opt->length).hh == TRUE || (opt->length).h == TRUE
			|| (opt->length).z == TRUE)
		set_max_length_hh_h_z(opt);
	return (opt);
}
