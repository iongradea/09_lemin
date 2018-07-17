/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_atoi_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iongradea <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 16:57:55 by iongradea         #+#    #+#             */
/*   Updated: 2017/07/25 13:29:42 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_atoi_prtf(const char *str, int *i)
{
	int		nb;

	nb = 0;
	while (str[*i] != '\0' && str[*i] >= '0' && str[*i] <= '9')
	{
		nb = nb * 10 + str[*i] - '0';
		(*i)++;
	}
	return (nb);
}

void	ft_itoa_base_intmax(t_pos_size *ps, t_base baz, intmax_t value)
{
	int		i;

	i = ps->size_str - 1;
	if (ps->size_str == 0)
		return ;
	if (value == 0)
	{
		*(ps->total + ps->pos_str) = '0';
		return ;
	}
	while (value >= baz.base || value <= -baz.base)
	{
		(ps->total + ps->pos_str)[i] = baz.tab[ft_abs(value % baz.base)];
		i--;
		value = value / baz.base;
	}
	if (i == 0)
		(ps->total + ps->pos_str)[i] = baz.tab[ft_abs(value)];
}

void	ft_itoa_base_uintmax(t_pos_size *ps, t_base baz, uintmax_t value)
{
	int		i;

	i = ps->size_str - 1;
	if (ps->size_str == 0)
		return ;
	if (value == 0)
	{
		*(ps->total + ps->pos_str) = '0';
		return ;
	}
	while (value >= (unsigned int)baz.base)
	{
		(ps->total + ps->pos_str)[i] = baz.tab[value % baz.base];
		i--;
		value = value / baz.base;
	}
	if (i == 0)
		(ps->total + ps->pos_str)[i] = baz.tab[value];
}

int		get_base(t_format opt)
{
	if (opt.id == 'u' || opt.id == 'U' || is_signed_conv(opt))
		return (10);
	if (opt.id == 'b')
		return (2);
	if (is_octal_conv(opt))
		return (8);
	if (is_hexa_conv(opt))
		return (16);
	return (10);
}
