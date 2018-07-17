/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 16:45:18 by igradea           #+#    #+#             */
/*   Updated: 2017/01/01 17:02:39 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	dlen = i;
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dlen + ft_strlen(src));
}
