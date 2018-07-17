/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_ws_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:13:23 by igradea           #+#    #+#             */
/*   Updated: 2017/07/25 13:25:06 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t		ft_strlen_wchar_unicoded(wchar_t *s, t_format opt, t_pos_size *ps)
{
	size_t	len;
	int		i;

	i = 0;
	len = (s[i] == '\0' && opt.id == 'C') ? 1 : 0;
	ps->size_wchar_concat = len == 1 ? 1 : 0;
	while (s[i])
	{
		if (opt.precision >= 0
				&& len + (size_t)get_wchar_size(s[i]) > (size_t)opt.precision)
		{
			if (len != (size_t)opt.precision && ch_wc_val(s[i]) == WCHAR_ERR)
				return (ps->wchar_value_error = WCHAR_ERR);
			return (len);
		}
		else
		{
			if (ch_wc_val(s[i]) == WCHAR_ERR)
				return (ps->wchar_value_error = WCHAR_ERR);
			ps->size_wchar_concat = i + 1;
			len += (size_t)get_wchar_size(s[i]);
		}
		i++;
	}
	return (len);
}

void		set_pos_size_wchar_str(t_pos_size *ps, t_format opt)
{
	ps->size_total = ft_max(ps->size_str, opt.min_width);
	if (opt.flags.minus == TRUE)
		ps->pos_str = 0;
	else
		ps->pos_str = ps->size_total - ps->size_str;
}

void		set_s_to_null(wchar_t *s)
{
	ft_bzero(s, 28);
	((char*)s)[0] = '(';
	((char*)s)[4] = 'n';
	((char*)s)[8] = 'u';
	((char*)s)[12] = 'l';
	((char*)s)[16] = 'l';
	((char*)s)[20] = ')';
}
