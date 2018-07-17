/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 12:38:31 by igradea           #+#    #+#             */
/*   Updated: 2017/08/30 14:40:12 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len - 1;
	if (src <= dst && (size_t)(dst - src) <= len)
	{
		while (i && i >= len - (size_t)(dst - src))
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else if (src >= dst && (size_t)(src - dst) <= len)
	{
		i = (size_t)(src - dst - 1);
		ft_memcpy((unsigned char *)dst, (unsigned char *)src, i);
	}
	else
		ft_memcpy((unsigned char *)dst, (unsigned char *)src, len);
	return (dst);
}
