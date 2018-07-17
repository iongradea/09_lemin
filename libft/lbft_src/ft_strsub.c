/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:56:31 by igradea           #+#    #+#             */
/*   Updated: 2017/01/15 18:07:49 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!(res = ft_strnew(len)))
		return (NULL);
	ft_strncpy(res, s + start, len);
	return (res);
}
