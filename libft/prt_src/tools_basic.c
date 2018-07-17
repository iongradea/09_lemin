/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 21:47:32 by igradea           #+#    #+#             */
/*   Updated: 2017/07/25 13:14:40 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		init_struct_fmt(t_format *format)
{
	(format->flags).minus = FALSE;
	(format->flags).plus = FALSE;
	(format->flags).zero = FALSE;
	(format->flags).space = FALSE;
	(format->flags).diez = FALSE;
	(format->length).h = FALSE;
	(format->length).hh = FALSE;
	(format->length).l = FALSE;
	(format->length).ll = FALSE;
	(format->length).j = FALSE;
	(format->length).z = FALSE;
	format->min_width = NONE;
	format->precision = NONE;
	format->id = '\0';
	format->unspecified = '\0';
	return (TRUE);
}

int		init_struct_ps(t_pos_size *ps)
{
	ps->size_total = FALSE;
	ps->size_prep = FALSE;
	ps->size_prec = FALSE;
	ps->size_str = FALSE;
	ft_bzero(ps->prep, sizeof(ps->prep));
	ps->total = NULL;
	ps->pos_prep = FALSE;
	ps->pos_prec = FALSE;
	ps->pos_str = FALSE;
	ps->size_wchar_concat = FALSE;
	ps->wchar_value_error = FALSE;
	return (TRUE);
}

void	init_int_prepend(char *prepend, t_format opt, intmax_t nb)
{
	if (is_signed_conv(opt))
	{
		if (nb < 0)
			prepend[0] = '-';
		else if (opt.flags.plus == TRUE)
			prepend[0] = '+';
		else if (opt.flags.space == TRUE)
			prepend[0] = ' ';
	}
}

void	init_uint_prepend(char *prepend, t_format opt, uintmax_t nb)
{
	if (opt.id == 'p')
		ft_strcpy(prepend, "0x");
	else if (nb != 0 && is_octal_conv(opt) && opt.flags.diez == TRUE
			&& opt.precision == 0)
		ft_strcpy(prepend, "0");
	else if (nb == 0 && is_octal_conv(opt) && opt.precision == 0
			&& opt.flags.diez == TRUE)
		ft_strcpy(prepend, "0");
	else if ((nb == 0 || opt.precision != NONE) && is_octal_conv(opt))
		return ;
	else if (nb == 0 && (opt.id == 'x' || opt.id == 'X'))
		return ;
	else if (is_octal_conv(opt) && opt.flags.diez == TRUE)
		ft_strcpy(prepend, "0");
	else if (is_hexa_conv(opt) && opt.id == 'x' && opt.flags.diez == TRUE)
		ft_strcpy(prepend, "0x");
	else if (is_hexa_conv(opt) && opt.id == 'X' && opt.flags.diez == TRUE)
		ft_strcpy(prepend, "0X");
}

int		init_struct_base(t_base *baz, t_format fmt)
{
	int	i;

	i = 0;
	baz->base = get_base(fmt);
	while (i < 16)
	{
		if (i < 10)
			baz->tab[i] = i + '0';
		else
			baz->tab[i] = i - 10 + 'a';
		i++;
	}
	i = 0;
	if (ft_isupper(fmt.id))
	{
		while (i < 6)
		{
			baz->tab[10 + i] = i + 'A';
			i++;
		}
	}
	baz->tab[16] = '\0';
	return (TRUE);
}
