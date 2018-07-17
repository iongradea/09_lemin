/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:34:22 by igradea           #+#    #+#             */
/*   Updated: 2017/09/07 10:58:07 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0
# define ERRPR -1
# define NONE -2
# define WCHAR_ERR -3
# define N_OPTION -4

typedef struct	s_base
{
	char		tab[17];
	int			base;
}				t_base;

typedef struct	s_pos_size
{
	int			size_total;
	int			size_prep;
	int			size_prec;
	int			size_str;
	int			size_wchar_concat;
	int			wchar_value_error;
	char		prep[3];
	char		*total;
	int			pos_prep;
	int			pos_prec;
	int			pos_str;
	char		*out_str[1];
	int			size;
	int			size_prev;
}				t_pos_size;

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			diez;
}				t_flags;

typedef struct	s_length
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_length;

typedef struct	s_format
{
	t_flags		flags;
	int			min_width;
	int			precision;
	t_length	length;
	char		id;
	char		unspecified;
}				t_format;

int				length_opt_h(const char *fmt, int *i, t_length *len);
int				length_opt_l(const char *fmt, int *i, t_length *len);
int				min_width_opt(const char *fmt, int *i, t_format *opt,
							va_list ap);
int				precision_opt(const char *fmt, int *i, t_format *opt,
							va_list ap);
int				parser(const char *fmt, int *i, t_format *opt, va_list ap);

t_format		*over_comp_diez(t_format *opt);
t_format		*over_comp_0(t_format *opt);
t_format		*over_comp_sp(t_format *opt);
t_format		*reset_length(t_format *opt);
t_format		*set_max_length_hh_h_z(t_format *opt);
t_format		*set_max_length(t_format *opt);
t_format		*parsing_clean(t_format *opt);
t_format		*clean_precision_c_wc(t_format *opt);
t_format		*parsing_clean_special_c_b0(t_format *opt, char *s);

int				init_struct_fmt(t_format *format);
int				init_struct_ps(t_pos_size *ps);
void			init_int_prepend(char *prepend, t_format opt, intmax_t nb);
void			init_uint_prepend(char *prepend, t_format opt, uintmax_t nb);
int				init_struct_base(t_base *baz, t_format opt);
int				is_octal_conv(t_format opt);
int				is_hexa_conv(t_format opt);
int				get_base(t_format opt);
int				is_signed_conv(t_format opt);
int				is_unsigned_conv(t_format opt);

int				ft_atoi_prtf(const char *str, int *i);
void			ft_itoa_base_intmax(t_pos_size *ps, t_base baz,
									intmax_t value);
void			ft_itoa_base_uintmax(t_pos_size *ps, t_base baz,
									uintmax_t value);

int				d_convert(t_pos_size *ps, t_format opt, va_list ap);
int				u_convert(t_pos_size *ps, t_format opt, va_list ap);
int				s_convert(t_pos_size *ps, t_format opt, va_list ap);
int				c_convert(t_pos_size *ps, t_format *opt, va_list ap);
void			set_pos(t_pos_size *ps, t_format opt);
void			set_background(t_pos_size *ps, t_format opt);
int				str_format(const char **fmt, t_format *opt, t_pos_size *ps,
							va_list ap);
intmax_t		arg_signed_modifier(va_list ap, t_format opt);
uintmax_t		arg_unsigned_modifier(va_list ap, t_format opt);
int				add_format_str(const char **fmt, va_list ap, t_pos_size *ps);
int				add_other_part(const char *fmt, t_pos_size *ps);
int				apply_n_option(t_pos_size ps, va_list ap);
int				ft_printf(const char *fmt, ...);

int				get_wchar_size(wchar_t c);
void			encode_unicode(wint_t c, int *i, char *s);
int				ch_wc_val(wchar_t c);
size_t			ft_strlen_wchar_unicoded(wchar_t *s, t_format opt,
										t_pos_size *ps);
void			set_pos_size_wchar_str(t_pos_size *ps, t_format opt);
void			set_s_to_null(wchar_t *s);

int				ws_convert(t_pos_size *ps, t_format opt, va_list ap);
int				wc_convert(t_pos_size *ps, t_format opt, va_list ap);
#endif
