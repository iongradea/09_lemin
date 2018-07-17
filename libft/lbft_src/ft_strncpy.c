/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 14:48:15 by igradea           #+#    #+#             */
/*   Updated: 2017/01/01 15:01:26 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
		dst[i++] = '\0';
	return (dst);
}
