/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:34:48 by igradea           #+#    #+#             */
/*   Updated: 2017/07/24 14:34:18 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	set_pos_size_str(t_pos_size *ps, t_format opt, char *s)
{
	int	len;

	if (s != NULL)
		len = s[0] == '\0' && opt.id == 'c' ? 1 : ft_strlen(s);
	else
		len = ft_strlen(s);
	ps->size_str = opt.precision >= 0 ? ft_min(opt.precision, len) : len;
	ps->size_total = ft_max(ps->size_str, opt.min_width);
	if (opt.flags.minus == TRUE)
		ps->pos_str = 0;
	else
		ps->pos_str = ps->size_total - ps->size_str;
}

int			s_convert_aux(t_pos_size *ps, t_format opt, char *s)
{
	if (s == NULL && opt.id == 's')
	{
		if (!(s = (char*)malloc(7)))
			return (ERRPR);
		s = ft_strcpy(s, "(null)");
	}
	else
	{
		if (!(s = ft_strdup(s)))
			return (ERRPR);
	}
	init_struct_ps(ps);
	set_pos_size_str(ps, opt, s);
	if (!(ps->total = (char*)malloc(sizeof(char) * (ps->size_total + 1))))
		return (ERRPR);
	ft_bzero(ps->total, (size_t)(ps->size_total + 1));
	set_background(ps, opt);
	ft_memcpy(ps->total + ps->pos_str, s, ps->size_str);
	free(s);
	return (TRUE);
}

int			c_convert(t_pos_size *ps, t_format *opt, va_list ap)
{
	char	*s;
	int		ptr_n[1];

	s = NULL;
	if (opt->id == 'c')
	{
		*ptr_n = va_arg(ap, int);
		s = (char*)ptr_n;
	}
	else if (opt->id == '\0' && opt->unspecified != '\0')
	{
		s = (char*)ptr_n;
		s[0] = opt->unspecified;
	}
	ft_bzero(s + 1, 3);
	parsing_clean_special_c_b0(opt, s);
	return (s_convert_aux(ps, *opt, s));
}

int			s_convert(t_pos_size *ps, t_format opt, va_list ap)
{
	char	*s;

	s = va_arg(ap, char*);
	return (s_convert_aux(ps, opt, s));
}
