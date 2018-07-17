/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iongradea <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:49:26 by iongradea         #+#    #+#             */
/*   Updated: 2017/07/19 18:31:37 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static wchar_t	*local_init_wchar_s(wchar_t *s, t_pos_size *ps, t_format opt)
{
	wchar_t	*tmp;

	if (s == NULL)
	{
		if (!(s = (wchar_t*)malloc(sizeof(wchar_t) * 7)))
			return (NULL);
		set_s_to_null(s);
		ps->size_str = (int)ft_strlen_wchar_unicoded(s, opt, ps);
	}
	else
	{
		tmp = s;
		ps->size_str = (int)ft_strlen_wchar_unicoded(s, opt, ps);
		if (ps->wchar_value_error == WCHAR_ERR)
			return (s);
		if (!(s = (wchar_t*)malloc(((size_t)ps->size_wchar_concat + 1) * 4)))
			return (NULL);
		ft_bzero(s, ((size_t)ps->size_wchar_concat + 1) * 4);
		ft_memcpy(s, tmp, (size_t)ps->size_wchar_concat * 4);
	}
	return (s);
}

static int		ws_convert_aux(t_pos_size *ps, t_format opt, wchar_t *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_struct_ps(ps);
	if (!(s = local_init_wchar_s(s, ps, opt)))
		return (ERRPR);
	if (ps->wchar_value_error == WCHAR_ERR)
		return (WCHAR_ERR);
	set_pos_size_wchar_str(ps, opt);
	if (!(ps->total = (char*)malloc(sizeof(char) * (ps->size_total + 1))))
		return (ERRPR);
	set_background(ps, opt);
	if (*s == '\0' && opt.id == 'C')
		encode_unicode((wint_t)s[j], &i, ps->total + ps->pos_str);
	while (*(s + j) && j < ps->size_wchar_concat)
		encode_unicode((wint_t)s[j++], &i, ps->total + ps->pos_str);
	free(s);
	return (TRUE);
}

int				ws_convert(t_pos_size *ps, t_format opt, va_list ap)
{
	wchar_t	*s;

	s = va_arg(ap, wchar_t*);
	return (ws_convert_aux(ps, opt, s));
}

int				wc_convert(t_pos_size *ps, t_format opt, va_list ap)
{
	wchar_t	c;
	wchar_t	s[2];

	ft_bzero(s, 8);
	c = va_arg(ap, wchar_t);
	ft_memcpy(s, &c, 4);
	return (ws_convert_aux(ps, opt, s));
}
