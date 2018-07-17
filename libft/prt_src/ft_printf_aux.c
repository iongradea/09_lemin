/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:37:13 by igradea           #+#    #+#             */
/*   Updated: 2017/07/25 13:39:19 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	add_format_str(const char **fmt, va_list ap, t_pos_size *ps)
{
	char		*tmp;
	t_format	opt;
	int			ret;

	if ((ret = str_format(fmt, &opt, ps, ap)) == ERRPR)
		return (ERRPR);
	if (ret == N_OPTION)
		return (N_OPTION);
	if (ps->wchar_value_error == WCHAR_ERR)
		return (WCHAR_ERR);
	tmp = *(ps->out_str);
	if (!(*(ps->out_str) = ft_strnjoin(*(ps->out_str), ps->total,
					(size_t)ps->size, (size_t)ps->size_total)))
		return (ERRPR);
	free(ps->total);
	free(tmp);
	return (ps->size_total);
}

int	add_other_part(const char *fmt, t_pos_size *ps)
{
	char	*tmp;
	int		i;

	tmp = *(ps->out_str);
	i = 0;
	while (*(fmt + i) && *(fmt + i) != '%')
		i++;
	if (!(*(ps->out_str) = ft_strnjoin(*(ps->out_str), fmt,
					(size_t)ps->size, (size_t)i)))
		return (ERRPR);
	ps->size_prev = ps->size;
	free(tmp);
	return (i);
}

int	apply_n_option(t_pos_size ps, va_list ap)
{
	int		*n;

	n = va_arg(ap, int*);
	if (n != NULL)
		*n = ps.size;
	return (0);
}
