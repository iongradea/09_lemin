/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iongradea <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:00:51 by iongradea         #+#    #+#             */
/*   Updated: 2017/07/25 13:39:32 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_printf_aux_loop(const char **fmt, va_list ap, t_pos_size *ps)
{
	int		len;

	len = 0;
	if (**fmt == '%')
	{
		*fmt += 1;
		len = add_format_str(fmt, ap, ps);
		if (len == ERRPR)
			return (ERRPR);
		if (len == WCHAR_ERR)
			return (WCHAR_ERR);
		if (len == N_OPTION)
			len = apply_n_option(*ps, ap);
		ps->size += len;
	}
	else
	{
		if ((len = add_other_part(*fmt, ps)) == ERRPR)
			return (ERRPR);
		*fmt += len;
		ps->size += len;
	}
	return (ps->size);
}

static int	ft_printf_aux(const char *fmt, va_list ap, t_pos_size *ps)
{
	while (*fmt)
	{
		ft_printf_aux_loop(&fmt, ap, ps);
		if (ps->wchar_value_error == WCHAR_ERR)
			return (ps->size_prev);
	}
	return (ps->size);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_pos_size	ps;

	if (!(*(ps.out_str) = ft_strdup("")))
		return (ERRPR);
	ps.size = FALSE;
	ps.size_prev = FALSE;
	va_start(ap, fmt);
	ps.size = ft_printf_aux(fmt, ap, &ps);
	write(1, *(ps.out_str), ps.size);
	free(*(ps.out_str));
	va_end(ap);
	if (ps.wchar_value_error == WCHAR_ERR)
		return (ERRPR);
	return (ps.size);
}
