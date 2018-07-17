/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iongradea <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 22:59:07 by iongradea         #+#    #+#             */
/*   Updated: 2017/07/22 22:17:43 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	str_format(const char **fmt, t_format *opt, t_pos_size *ps, va_list ap)
{
	int		i;
	int		ret;

	i = 0;
	init_struct_fmt(opt);
	parser(*fmt, &i, opt, ap);
	*fmt += i;
	if (opt->id == 'n')
		return (N_OPTION);
	if (opt->id == '\0' && opt->unspecified == '\0')
		return (ERRPR);
	parsing_clean(opt);
	if (is_signed_conv(*opt))
		ret = d_convert(ps, *opt, ap);
	else if (is_unsigned_conv(*opt))
		ret = u_convert(ps, *opt, ap);
	else if (opt->id == 'C')
		ret = wc_convert(ps, *opt, ap);
	else if (opt->id == 'S')
		ret = ws_convert(ps, *opt, ap);
	else if (opt->id == 's')
		ret = s_convert(ps, *opt, ap);
	else
		ret = c_convert(ps, opt, ap);
	return (ret);
}
