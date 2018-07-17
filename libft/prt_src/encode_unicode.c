/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:19:14 by igradea           #+#    #+#             */
/*   Updated: 2017/07/22 14:10:12 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ch_wc_val(wchar_t c)
{
	if (c < 0 || c > 0x10ffff)
		return (WCHAR_ERR);
	return (TRUE);
}

int		get_wchar_size(wchar_t c)
{
	int	len;

	len = 4;
	if (c >= 0 && c <= 0x7f)
		len = 1;
	if (c >= 0x80 && c <= 0x7ff)
		len = 2;
	if ((c >= 0x800 && c <= 0xd7ff) || (c >= 0xe000 && c <= 0xffff))
		len = 3;
	if (c >= 0x10000 && c <= 0x10ffff)
		len = 4;
	return (len);
}

void	encode_unicode(wint_t c, int *i, char *s)
{
	if (c <= 0x7f)
		s[(*i)++] = (char)c;
	else if (c >= 0x80 && c <= 0x7ff)
	{
		s[(*i)++] = (char)(0xc0 | (c >> 6));
		s[(*i)++] = (char)(0x80 | (0x3f & c));
	}
	else if (c >= 0x800 && c <= 0xffff)
	{
		s[(*i)++] = (char)(0xe0 | (0xf & (c >> 12)));
		s[(*i)++] = (char)(0x80 | (0x3f & (c >> 6)));
		s[(*i)++] = (char)(0x80 | (0x3f & c));
	}
	else if (c >= 0x10000 && c <= 0x10ffff)
	{
		s[(*i)++] = (char)(0xf0 | (0x7 & (c >> 18)));
		s[(*i)++] = (char)(0x80 | (0x3f & (c >> 12)));
		s[(*i)++] = (char)(0x80 | (0x3f & (c >> 6)));
		s[(*i)++] = (char)(0x80 | (0x3f & c));
	}
}
